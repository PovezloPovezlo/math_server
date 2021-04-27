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
