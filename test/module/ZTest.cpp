#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/z.h>

using namespace base;
using namespace module;

// тесты
TEST(Z, ABS_Z_N)
{
	LongNumber a("12345");
	ULongNumber b("12345");
	EXPECT_EQ(ABS_Z_N(a), b);

	a = LongNumber("-12345");
	b= ULongNumber("12345");
	EXPECT_EQ(ABS_Z_N(a), b);
}

TEST(Z, POZ_Z_D)
{
	LongNumber a("12345");
	EXPECT_EQ(POZ_Z_D(a), 2);

	a = LongNumber("-12345");
	EXPECT_EQ(POZ_Z_D(a), 1);

	a = LongNumber("0");
	EXPECT_EQ(POZ_Z_D(a), 0);
}

TEST(Z, MUL_ZM_Z)
{
	LongNumber a("543354");
	LongNumber b("-543354");
	EXPECT_EQ(MUL_ZM_Z(a), b);

	a = LongNumber("-457457458");
	b = LongNumber("457457458");
	EXPECT_EQ(MUL_ZM_Z(a), b);

}

TEST(Z, TRANS_N_Z)
{
	NLongNumber a("543354");
	LongNumber b("543354");
	EXPECT_EQ(TRANS_N_Z(a), b);

	a = NLongNumber("457457458");
	b = LongNumber("457457458");
	EXPECT_EQ(TRANS_N_Z(a), b);

}

TEST(Z, TRANS_Z_N)
{
	ULongNumber a("543354");
	NLongNumber b("543354");
	EXPECT_EQ(TRANS_Z_N(a), b);

	a = ULongNumber("457457458");
	b = NLongNumber("457457458");
	EXPECT_EQ(TRANS_Z_N(a), b);

}
