//
// Created by NolikTop on 26.04.2021.
//


#pragma once

#include "LongNumber.h"

namespace base {

	class ULongNumber : public LongNumber {
	public:
		explicit ULongNumber(std::string value);

		static ULongNumber empty();

	};

}
