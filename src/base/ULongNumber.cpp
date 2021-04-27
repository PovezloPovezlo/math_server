#include "ULongNumber.h"

#include <utility>
#include "LongNumberException.h"

using namespace base;

ULongNumber::ULongNumber(std::string value) : LongNumber(std::move(value)) {
	if(!this->isPositive){
		throw LongNumberException("ULongNumber can contain only non-negative numbers");
	}
}

ULongNumber ULongNumber::empty() {
	return ULongNumber("0");
}
