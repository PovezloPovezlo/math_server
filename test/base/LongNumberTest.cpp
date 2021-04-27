//
// Created by NolikTop on 20.04.2021.
//

#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/LongNumberException.h>

TEST(LongNumberBase, getDigitAt){
	base::LongNumber positiveNumber("1489294814");

	EXPECT_EQ(positiveNumber[3], 9);
	EXPECT_EQ(positiveNumber[positiveNumber.lastElementIndex() - 3], 4);


	base::LongNumber negativeNumber("-1489294814");

	EXPECT_EQ(negativeNumber[3], 9);
	EXPECT_EQ(negativeNumber[negativeNumber.lastElementIndex() - 3], 4);
}

TEST(LongNumberBase, inputCheck){
	try {
		base::LongNumber wrongNumber("abc");
		FAIL() << "LongNumber can't contain \"abc\" number";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("-abc");
		FAIL() << "LongNumber can't contain \"-abc\" number";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("");
		FAIL() << "LongNumber can't contain empty number";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}

	try {
		base::LongNumber wrongNumber("-");
		FAIL() << "LongNumber can't contain empty negative (just \"-\") number";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}
}

TEST(ULongNumberBase, inputCheck){
	try {
		base::ULongNumber wrongNumber("-1489294814");
		FAIL() << "ULongNumber shouldn't accept negative numbers";
	}catch(base::LongNumberException &exception){
		SUCCEED();
	}
}