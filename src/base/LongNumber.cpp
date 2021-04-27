//
// Created by NolikTop on 20.04.2021.
//

#include "LongNumber.h"
#include "LongNumberException.h"
#include <vector>

using namespace base;

LongNumber::LongNumber(std::string value) {
	if(
		value.length() == 0 ||
		(value[0] == '-' && value.length() == 1)
	){
		throw LongNumberException("Value must be not empty");
	}

	this->isPositive = value[0] != '-';

	const size_t firstDigitIndex = this->isPositive ? 0 : 1;

	if(value[firstDigitIndex] == '0' && value.length() > firstDigitIndex + 1){
		throw LongNumberException("Number cant starts with 0 digit if its not equal 0");
	}

	for(
		size_t i = firstDigitIndex;
		i < value.length();
		++i
	){
		if(value[i] >= '0' && value[i] <= '9') {
			this->digits.push_back(value[i] - '0');
		}else{
			throw LongNumberException("Unknown symbol '" + std::to_string(value[i]) + "'");
		}
	}

}

size_t LongNumber::length() const {
	return this->digits.size();
}

size_t LongNumber::lastElementIndex() const {
	return this->length() - 1;
}

DIGIT &LongNumber::operator[](size_t index) {
	return this->digits[index];
}

std::string LongNumber::toString() {
	//todo
	return std::string();
}

LongNumber LongNumber::empty() {
	return LongNumber("0");
}