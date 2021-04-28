#pragma once

#include "LongNumber.h"

namespace base {

	// Натуральное число с нулем (неотрицательное целое число)
	class ULongNumber : public LongNumber {
	public:
		explicit ULongNumber(std::string value);
		explicit ULongNumber(unsigned int value);

		static ULongNumber empty();
		static ULongNumber fromInt(unsigned int value);
	};

}
