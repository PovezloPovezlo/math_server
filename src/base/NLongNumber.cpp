#include "NLongNumber.h"

using namespace base;

NLongNumber::NLongNumber(std::string value) : ULongNumber(std::move(value)){
	if(this->operator[](0) == 0){
		throw LongNumberException("NLongNumber can contain only positive numbers");
	}
}