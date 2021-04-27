#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/LongNumberException.h>
#include <base/NLongNumber.h>

TEST(LongNumber, getDigit){
	base::LongNumber positiveNumber("1489294814");

	EXPECT_EQ(positiveNumber[3], 9);
	EXPECT_EQ(positiveNumber[positiveNumber.lastElementIndex() - 3], 4);


	base::LongNumber negativeNumber("-1489294814");

	EXPECT_EQ(negativeNumber[3], 9);
	EXPECT_EQ(negativeNumber[negativeNumber.lastElementIndex() - 3], 4);
}

TEST(LongNumber, inputCheck){
	try {
		base::LongNumber wrongNumber("abc");
		base::LongNumber negativeWrongNumber("-abc");

		FAIL() << "LongNumber shouldn't contain non-digit symbols";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("");

		FAIL() << "LongNumber shouldn't contain empty number";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("-");

		FAIL() << "LongNumber shouldn't contain empty negative number (just \"-\")";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try{
		base::LongNumber wrongNumber("01");
		base::LongNumber negativeWrongNumber("-01");

		FAIL() << "Number shouldn't start with 0 digit if its not equal 0";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}
}

TEST(ULongNumber, inputCheck){
	try {
		base::ULongNumber wrongNumber("-1489294814");

		FAIL() << "ULongNumber shouldn't accept negative numbers";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}
}

TEST(NLongNumber, inputCheck){
	try{
		base::NLongNumber wrongNumber("0");

		FAIL() << "NLongNumber shouldn't accept zero number";
	}catch(base::NLongNumber &exception){
		SUCCEED();
	}
}