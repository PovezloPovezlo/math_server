//
// Created by NolikTop on 20.04.2021.
//

#include "LongNumber.h"

using namespace base;

LongNumber::LongNumber(std::string value) {
	this->isPositive = value[0] != '-';
	if(!this->isPositive) {
		value = value.substr(1);
	}

	//todo validation
	this->data = value;
}

size_t LongNumber::length() const {
	return this->data.length();
}

DIGIT LongNumber::getDigitAt(size_t pos) {
	if(pos >= this->length()){
		throw std::out_of_range("Out of range");
	}

	return this->data[this->length() - 1 - pos] - '0';
}

DIGIT LongNumber::getDigitFromEndAt(size_t pos) {
	return this->getDigitAt(this->length() - 1 - pos);
}
