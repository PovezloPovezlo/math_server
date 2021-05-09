#include "RationalFraction.h"

#include <utility>

using namespace base;

RationalFraction::RationalFraction(LongNumber numerator, NLongNumber denominator) : numerator(std::move(numerator)), denominator(std::move(denominator)) {}

RationalFraction::RationalFraction(int value) : numerator(value), denominator(1) {}

std::string RationalFraction::toString() {
	if(this->denominator.toString() == "1" || this->numerator.toString() == "0"){ //todo заменить вызов на INT_Q_B после того как сделвют эту функцию
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

RationalFraction RationalFraction::fromInt(size_t value) {
	return RationalFraction(LongNumber::fromInt(value), NLongNumber::fromInt(1));
}

RationalFraction RationalFraction::fromTwoInt(int numerator, unsigned int denominator) {
	return RationalFraction((base::LongNumber)numerator, (base::NLongNumber)denominator);
}

//todo make tests
RationalFraction RationalFraction::fromString(std::string val) {
	auto endOfNumerator = val.find('/');
	if(endOfNumerator == std::string::npos){
		return RationalFraction(LongNumber(val), NLongNumber::fromInt(1));
	}

	auto numeratorStr = val.substr(0, endOfNumerator);
	auto denominatorStr = val.substr(endOfNumerator+1);

	auto numerator = LongNumber(numeratorStr);
	auto denominator = NLongNumber(denominatorStr);

	return RationalFraction(numerator, denominator);
}
