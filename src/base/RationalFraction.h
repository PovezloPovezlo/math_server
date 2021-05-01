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
		explicit RationalFraction(int value);

		std::string toString();

		static RationalFraction empty();
		static RationalFraction fromInt(int value);
		static RationalFraction fromTwoInt(int numerator, unsigned int denominator);
	};

}
