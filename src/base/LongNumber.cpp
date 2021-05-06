#include "LongNumber.h"
#include "BaseException.h"
#include <vector>

using namespace base;

LongNumber::LongNumber(std::string value) {
	if(
		value.length() == 0 ||
		(value[0] == '-' && value.length() == 1)
	){
		throw BaseException("Value must be not empty");
	}

	this->isPositive = value[0] != '-';

	const size_t firstDigitIndex = this->isPositive ? 0 : 1;

	if(value[firstDigitIndex] == '0' && value.length() > firstDigitIndex + 1){
		throw BaseException("Number can't starts with 0 digit if its not equal 0");
	}

	for(
		size_t i = value.length() - 1;
		;
		--i
	){
		if(value[i] >= '0' && value[i] <= '9') {
			this->digits.push_back(value[i] - '0');
		}else{
			throw BaseException("Unknown symbol '" + std::to_string(value[i]) + "'");
		}

		if(i == firstDigitIndex){ // условие здесь, а не в for, так как может произойти int overflow (i станет не -1, а очень большим положительным числом (uint64.MaxValue)
			break;
		}
	}



}

LongNumber::LongNumber(size_t size, bool isPositive) : isPositive(isPositive) {
	for(int i = 0; i < size; ++i){
		this->digits.push_back(0);
	}
}

size_t LongNumber::length() const {
    size_t c = 0;

    bool deleteZeros = true;

    for(auto i = this->digits.rbegin(); i != this->digits.rend(); ++i){
        if(deleteZeros) {
            if (*i != 0) {
                deleteZeros = false;
            }else{
                continue;
            }
        }

        ++c;
    }

    return c > 1 ? c : 1;
}

size_t LongNumber::realLength() const {
    return this->digits.size();
}

size_t LongNumber::lastElementIndex() const {
	// гарантируется, что длина будет >= 1, поэтому нет необходимости писать проверку на нулевую длину
	return this->length() - 1;
}

DIGIT &LongNumber::operator[](size_t index) {
	if(index >= realLength()){
		if(index >= this->digits.capacity()){
			this->digits.reserve(index);
		}
		for(size_t i = lastElementIndex(); i < index; ++i){
			this->digits.push_back(0);
		}
	}

	return this->digits[index];
}

bool LongNumber::operator==(const LongNumber& number) const {
	if(this->isPositive != number.isPositive || this->length() != number.length()){
		return false;
	}

	auto l = this->length();

	for(int i = 0; i < l; ++i){
		if(this->digits[i] != number.digits[i]){
			return false;
		}
	}

	return true;
}

bool LongNumber::operator!=(const LongNumber &number) const {
	return !(*this == number);
}

std::string LongNumber::toString() {
	this->deleteRedundantZeros();

	std::string result;

	auto l = length();
	
	for(auto i = 0; i < l; ++i){
		result = std::to_string(this->operator[](i)) + result;
	}

	if (!this->isPositive) {
		result = "-" + result;
	}

	return result;
}

void LongNumber::deleteRedundantZeros() {
	for(auto i = this->digits.rbegin(); i != std::prev(this->digits.rend()); ++i){
		auto d = *i;
		if(d != 0){
			return;
		}
	}
}

LongNumber LongNumber::empty() {
	return LongNumber("0");
}

LongNumber LongNumber::fromInt(int value) {
	return LongNumber(std::to_string(value));
}

//todo optimize (избавиться от to_string())
LongNumber::LongNumber(int value) : LongNumber(std::to_string(value)){}

bool LongNumber::isZero() const {
    return this->length() == 1 && this->digits[0] == 0;
}
