#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/n.h>

using namespace base;
using namespace module;

// тесты

//ADD_NN_N_TEST
TEST(LongNumber, ADD_NN_N) {
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(0), ULongNumber(0)), ULongNumber(0));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(0), ULongNumber(1)), ULongNumber(1));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(1), ULongNumber(0)), ULongNumber(1));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(1), ULongNumber(1)), ULongNumber(2));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(9), ULongNumber(9)), ULongNumber(18));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(9), ULongNumber(0)), ULongNumber(9));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(1), ULongNumber(9)), ULongNumber(10));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(99), ULongNumber(1)), ULongNumber(100));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(1), ULongNumber(99)), ULongNumber(100));
	EXPECT_EQ(module::ADD_NN_N(ULongNumber(99), ULongNumber(99)), ULongNumber(198));
}