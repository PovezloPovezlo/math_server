#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/n.h>

using namespace base;
using namespace module;

// тесты
TEST(N, COM_NN_D)
{
	ULongNumber a("12345");
	ULongNumber b("56788");
	ULongNumber c("634");
	ULongNumber d("12345");
	EXPECT_EQ(COM_NN_D(a, b), 1);
	EXPECT_EQ(COM_NN_D(b, c), 2);
	EXPECT_EQ(COM_NN_D(d, a), 0);
	EXPECT_EQ(COM_NN_D(c, d), 1);
}

TEST(N, NZER_N_B)
{
	ULongNumber a("321656");
	EXPECT_EQ(NZER_N_B(a), false);
	a = ULongNumber("3405053653600854343430");
	EXPECT_EQ(NZER_N_B(a), false);
	a = ULongNumber("0");
	EXPECT_EQ(NZER_N_B(a), true);
}

TEST(N, ADD_1N_N)
{
	ULongNumber a("123");
	ULongNumber b("124");
	EXPECT_EQ(ADD_1N_N(a), b);
	a = ULongNumber("999");
	b = ULongNumber("1000");
	EXPECT_EQ(ADD_1N_N(a), b);
	a = ULongNumber("0");
	b = ULongNumber("1");
	EXPECT_EQ(ADD_1N_N(a), b);
	a = ULongNumber("9999999999999999999999999999999999999999");
	b = ULongNumber("10000000000000000000000000000000000000000");
	EXPECT_EQ(ADD_1N_N(a), b);
	a = ULongNumber("27568752672546528576700329890291050478020104798345167814565342");
	b = ULongNumber("27568752672546528576700329890291050478020104798345167814565343");
	EXPECT_EQ(ADD_1N_N(a), b);
	a = ULongNumber("12345670000000000000000000000089999");
	b = ULongNumber("12345670000000000000000000000090000");
	EXPECT_EQ(ADD_1N_N(a), b);

}