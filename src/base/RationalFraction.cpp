#include "RationalFraction.h"

#include <utility>

using namespace base;

RationalFraction::RationalFraction(LongNumber numerator, NLongNumber denominator) : numerator(std::move(numerator)), denominator(std::move(denominator)) {}

RationalFraction::RationalFraction(int value) : numerator(value), denominator(1) {}

std::string RationalFraction::toString() const {
	if(this->denominator.toString() == "1"){ //todo заменить вызов на INT_Q_B
		return this->numerator.toString();
	}
	return this->numerator.toString() + "/" + this->denominator.toString();
}

RationalFraction RationalFraction::empty() {
	return RationalFraction(LongNumber::empty(), NLongNumber::fromInt(1));
}

RationalFraction RationalFraction::fromInt(int value) {
	return RationalFraction(LongNumber::fromInt(value), NLongNumber::fromInt(1));
}

RationalFraction RationalFraction::fromTwoInt(int numerator, unsigned int denominator) {
	return RationalFraction((base::LongNumber)numerator, (base::NLongNumber)denominator);
}
