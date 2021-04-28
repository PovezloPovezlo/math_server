#include <gtest/gtest.h>
#include <base/RationalFraction.h>

TEST(RationalFraction, toString){
	base::RationalFraction number(base::LongNumber::fromInt(6), base::NLongNumber::fromInt(4));

	EXPECT_EQ(number.toString(), "6/4");
}