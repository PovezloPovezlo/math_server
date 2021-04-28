#include "NLongNumber.h"

using namespace base;

NLongNumber::NLongNumber(std::string value) : ULongNumber(std::move(value)){
	if(this->digits[0] == 0){
		throw BaseException("NLongNumber can contain only positive numbers");
	}
}

NLongNumber::NLongNumber(unsigned int value) : NLongNumber(std::to_string(value)) {}

NLongNumber NLongNumber::fromInt(unsigned int value) {
	return NLongNumber(std::to_string(value));
}

