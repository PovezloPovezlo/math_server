#include "NLongNumber.h"

using namespace base;

NLongNumber::NLongNumber(std::string value) : ULongNumber(std::move(value)){
	if(this->length() == 1 && this->digits[0] == 0){
		throw BaseException("NLongNumber can contain only positive numbers");
	}
}

NLongNumber::NLongNumber(unsigned int value) : NLongNumber(std::to_string(value)) {}

NLongNumber NLongNumber::fromInt(unsigned int value) {
	return NLongNumber(std::to_string(value));
}

NLongNumber NLongNumber::fromLongNumber(LongNumber &value) {
    if(!value.isPositive){
        throw BaseException("Cant convert negative LongNumber to ULongNumber");
    }

    if (value.length() == 1 && value[0] == 0)
    {
        //При нуле вылетает ошибка
        throw BaseException("zero is not natural number");
    }

    NLongNumber number(1);
    number.digits.erase(number.digits.begin());
    std::copy(value.digits.begin(), value.digits.end(), std::back_inserter(number.digits));

    return number;
}

