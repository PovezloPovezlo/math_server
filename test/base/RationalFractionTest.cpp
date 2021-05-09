#include <gtest/gtest.h>
#include <base/RationalFraction.h>

TEST(RationalFraction, toString){
	auto number = base::RationalFraction::fromTwoInt(6, 4);
	EXPECT_EQ(number.toString(), "6/4");

	auto number2 = base::RationalFraction::fromTwoInt(4, 1);
	EXPECT_EQ(number2.toString(), "4");

	auto number3 = base::RationalFraction::fromTwoInt(6, 2);
	//todo в будущем EXPECT_EQ(number3.toString(), "3");
}

/*
TEST(RationalFraction, fromString){
	auto number = base::RationalFraction::fromString("4/3");
	EXPECT_EQ(number.toString(), "4/3");
	auto number2 = base::RationalFraction::fromString("1");
	EXPECT_EQ(number2.toString(), "1");
}
*/