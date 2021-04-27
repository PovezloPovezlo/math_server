//
// Created by NolikTop on 26.04.2021.
//


#pragma once

#include "LongNumber.h"
#include "ULongNumber.h"
#include "NLongNumber.h"

namespace base {

	class RationalFraction {
	public:
		LongNumber numerator;
		NLongNumber denominator;

		RationalFraction(LongNumber numerator, NLongNumber denominator);

	};

}
