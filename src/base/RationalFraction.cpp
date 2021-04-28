#include "RationalFraction.h"

#include <utility>

using namespace base;

RationalFraction::RationalFraction(LongNumber numerator, NLongNumber denominator) : numerator(std::move(numerator)), denominator(std::move(denominator)) {}

std::string RationalFraction::toString() {
	return this->numerator.toString() + "/" + this->denominator.toString();
}

RationalFraction RationalFraction::empty() {
	return RationalFraction(LongNumber::empty(), NLongNumber::fromInt(1));
}