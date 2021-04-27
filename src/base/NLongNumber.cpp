#include "NLongNumber.h"

using namespace base;

NLongNumber::NLongNumber(std::string value) : ULongNumber(std::move(value)){
	if(this->digits[0] == 0){
		throw LongNumberException("NLongNumber can contain only positive numbers");
	}
}

NLongNumber NLongNumber::fromInt(unsigned int value) {
	return NLongNumber(std::to_string(value));
}
