//
// Created by NolikTop on 26.04.2021.
//

#include "NLongNumber.h"

using namespace base;

NLongNumber::NLongNumber(std::string value) : ULongNumber(std::move(value)){
	if(this->getDigitAt(0) == 0){
		throw LongNumberException("NLongNumber can contain only positive numbers");
	}
}