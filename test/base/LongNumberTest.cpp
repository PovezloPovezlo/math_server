#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/BaseException.h>
#include <base/NLongNumber.h>

TEST(LongNumber, getDigit){
	base::LongNumber positiveNumber("1489294814");

	EXPECT_EQ(positiveNumber[3], 4);
	EXPECT_EQ(positiveNumber[positiveNumber.lastElementIndex() - 3], 9);


	base::LongNumber negativeNumber("-1489294814");

	EXPECT_EQ(negativeNumber[3], 4);
	EXPECT_EQ(negativeNumber[negativeNumber.lastElementIndex() - 3], 9);
}

TEST(LongNumber, toString){
	base::LongNumber positiveNumber("1489294814");

	EXPECT_EQ(positiveNumber.toString(), "1489294814");

	base::LongNumber negativeNumber("-1489294814");

	EXPECT_EQ(negativeNumber.toString(), "-1489294814");
}

TEST(LongNumber, allocation){
	base::LongNumber positiveNumber(10, true);

	EXPECT_EQ(positiveNumber.length(), 10);
	EXPECT_EQ(positiveNumber.isPositive, true);

	base::LongNumber negativeNumber(10, false);
	EXPECT_EQ(negativeNumber.length(), 10);
	EXPECT_EQ(negativeNumber.isPositive, false);

	base::LongNumber number("228");
	number[3] = 5;
	number[5] = 9;

	EXPECT_EQ(number.toString(), "905228");
}

TEST(LongNumber, equals){
	base::LongNumber number("1489294814");
	base::LongNumber negativeNumber("-1489294814");

	base::LongNumber similarNumber("1489294414");
	base::LongNumber notSimilarNumber("228");
    base::LongNumber sameNumber("1489294814");

    EXPECT_NE(number, negativeNumber);
	EXPECT_NE(number, similarNumber);
	EXPECT_NE(number, notSimilarNumber);
	EXPECT_EQ(number, sameNumber);
}

TEST(LongNumber, inputCheck){
	try {
		base::LongNumber wrongNumber("abc");
		base::LongNumber negativeWrongNumber("-abc");

		FAIL() << "LongNumber shouldn't contain non-digit symbols";
	}catch(base::BaseException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("");

		FAIL() << "LongNumber shouldn't contain empty number";
	}catch(base::BaseException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("-");

		FAIL() << "LongNumber shouldn't contain empty negative number (just \"-\")";
	}catch(base::BaseException &exception){
		SUCCEED();
	}

	try{
		base::LongNumber wrongNumber("01");
		base::LongNumber negativeWrongNumber("-01");

		FAIL() << "Number shouldn't start with 0 digit if its not equal 0";
	}catch(base::BaseException &exception){
		SUCCEED();
	}
}

TEST(ULongNumber, inputCheck){
	try {
		base::ULongNumber wrongNumber("-1489294814");

		FAIL() << "ULongNumber shouldn't accept negative numbers";
	}catch(base::BaseException &exception){
		SUCCEED();
	}
}

TEST(NLongNumber, inputCheck){
	try{
		base::NLongNumber wrongNumber("0");

		FAIL() << "NLongNumber shouldn't accept zero number";
	}catch(base::BaseException &exception){
		SUCCEED();
	}
}