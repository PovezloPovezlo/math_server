#pragma once

#include "LongNumber.h"

namespace base {

	class ULongNumber : public LongNumber {
	public:
		explicit ULongNumber(std::string value);

		static ULongNumber empty();

	};

}
