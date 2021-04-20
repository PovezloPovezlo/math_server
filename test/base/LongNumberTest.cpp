//
// Created by NolikTop on 20.04.2021.
//

#include <gtest/gtest.h>
#include <base/LongNumber.h>

TEST(LongNumberBase, getDigitAt){
	base::LongNumber positiveNumber("1489294814");

	EXPECT_EQ(positiveNumber.getDigitAt(3), 4);
	EXPECT_EQ(positiveNumber.getDigitFromEndAt(3), 9);


	base::LongNumber negativeNumber("-1489294814");

	EXPECT_EQ(negativeNumber.getDigitAt(3), 4);
	EXPECT_EQ(negativeNumber.getDigitFromEndAt(3), 9);
}