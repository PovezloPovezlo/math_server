#include "ULongNumber.h"

#include <utility>
#include "BaseException.h"

using namespace base;

ULongNumber::ULongNumber(std::string value) : LongNumber(std::move(value)) {
	if(!this->isPositive){
		throw BaseException("ULongNumber can contain only non-negative numbers");
	}
}

ULongNumber::ULongNumber(unsigned int value) : ULongNumber(std::to_string(value)) {}

ULongNumber ULongNumber::empty() {
	return ULongNumber("0");
}

ULongNumber ULongNumber::fromInt(unsigned int value) {
	return ULongNumber(std::to_string(value));
}
