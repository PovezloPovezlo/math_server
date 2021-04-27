//
// Created by NolikTop on 26.04.2021.
//


#pragma once

#include "ULongNumber.h"
#include "LongNumberException.h"

namespace base {

	class NLongNumber : public ULongNumber {
	public:
		explicit NLongNumber(std::string value);

	};

}
