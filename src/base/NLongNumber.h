#pragma once

#include "ULongNumber.h"
#include "BaseException.h"

namespace base {

	class NLongNumber : public ULongNumber {
	public:
		explicit NLongNumber(std::string value);
		explicit NLongNumber(unsigned int value);

		static NLongNumber fromInt(unsigned int value);
	};

}
