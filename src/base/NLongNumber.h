#pragma once

#include "ULongNumber.h"
#include "LongNumberException.h"

namespace base {

	class NLongNumber : public ULongNumber {
	public:
		explicit NLongNumber(std::string value);

		static NLongNumber fromInt(unsigned int value);
	};

}
