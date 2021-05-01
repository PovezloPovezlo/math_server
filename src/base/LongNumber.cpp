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
	return this->digits.size();
}

size_t LongNumber::lastElementIndex() const {
	// гарантируется, что длина будет >= 1, поэтому нет необходимости писать проверку на нулевую длину
	return this->length() - 1;
}

DIGIT &LongNumber::operator[](size_t index) {
	if(index >= length()){
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

	for(int i = 0; i < this->length(); ++i){
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
	if(!this->isPositive){
		result += "-";
	}
	for(auto i = digits.rbegin(); i < digits.rend(); ++i){
		result += std::to_string(*i);
	}

	return result;
}

void LongNumber::deleteRedundantZeros() {
	for(auto i = this->digits.rbegin(); i != this->digits.rend() - 1; ++i){
		auto d = *i;
		if(d != 0){
			return;
		}

		this->digits.erase(std::next(i).base());
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
