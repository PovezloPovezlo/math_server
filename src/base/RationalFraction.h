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
		static RationalFraction fromInt(size_t value);
		static RationalFraction fromTwoInt(int numerator, unsigned int denominator);
		static RationalFraction fromString(std::string val);
	};

}
