#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/z.h>

using namespace base;
using namespace module;

// тесты

TEST(Z, MUL_ZZ_Z){
    LongNumber a("111111111111111111111111111111");
    LongNumber b("222222222222222222222222222222");
    LongNumber c("-111111111111111111111111111111");
    LongNumber k("3");

    auto t1 = MUL_ZZ_Z(a, b);
    auto t2 = MUL_ZZ_Z(b, c);
    auto t3 = MUL_ZZ_Z(a, k);

    auto t4 = MUL_ZZ_Z(c, k);

    EXPECT_EQ(t1.toString(), "24691358024691358024691358024641975308641975308641975308642");
    EXPECT_EQ(t2.toString(), "-24691358024691358024691358024641975308641975308641975308642");
    EXPECT_EQ(t3.toString(), "333333333333333333333333333333");
    EXPECT_EQ(t4.toString(), "-333333333333333333333333333333");

	LongNumber l(120), j(196), v(326), o(156);
	EXPECT_EQ(MUL_ZZ_Z(l, j).toString(), "23520");
	EXPECT_EQ(MUL_ZZ_Z(v, o).toString(), "50856");
}

TEST(Z, ABS_Z_N)
{
	LongNumber a("36454362134243");
	ULongNumber b("36454362134243");
	EXPECT_EQ(ABS_Z_N(a).toString(), b.toString());

	a = LongNumber("-54343545543");
	b= ULongNumber("54343545543");
	EXPECT_EQ(ABS_Z_N(a).toString(), b.toString());

	a = LongNumber("0");
	b = ULongNumber("0");
	EXPECT_EQ(ABS_Z_N(a).toString(), b.toString());
}

TEST(Z, POZ_Z_D)
{
	LongNumber a("653756334643234");
	EXPECT_EQ(POZ_Z_D(a), 2);

	a = LongNumber("-7658413245233457");
	EXPECT_EQ(POZ_Z_D(a), 1);

	a = LongNumber("0");
	EXPECT_EQ(POZ_Z_D(a), 0);

	a = LongNumber("5");
	EXPECT_EQ(POZ_Z_D(a), 2);

	a = LongNumber("-7");
	EXPECT_EQ(POZ_Z_D(a), 1);
}

TEST(Z, MUL_ZM_Z)
{
	LongNumber a("3545343563456635");
	LongNumber b("-3545343563456635");
	EXPECT_EQ(MUL_ZM_Z(a).toString(), b.toString());

	a = LongNumber("-46746574567746647");
	b = LongNumber("46746574567746647");
	EXPECT_EQ(MUL_ZM_Z(a).toString(), b.toString());

	a = LongNumber("0");
	b = LongNumber("0");
	EXPECT_EQ(MUL_ZM_Z(a).toString(), b.toString());

}

TEST(Z, TRANS_N_Z)
{
	NLongNumber a("543354");
	LongNumber b("543354");
	EXPECT_EQ(TRANS_N_Z(a).toString(), b.toString());

	a = NLongNumber("457457458");
	b = LongNumber("457457458");
	EXPECT_EQ(TRANS_N_Z(a).toString(), b.toString());

	a = NLongNumber("4");
	b = LongNumber("4");
	EXPECT_EQ(TRANS_N_Z(a).toString(), b.toString());

}

TEST(Z, TRANS_Z_N)
{
	ULongNumber a("543354");
	NLongNumber b("543354");
	EXPECT_EQ(TRANS_Z_N(a).toString(), b.toString());

	a = ULongNumber("457457458");
	b = NLongNumber("457457458");
	EXPECT_EQ(TRANS_Z_N(a).toString(), b.toString());

	a = ULongNumber("3");
	b = NLongNumber("3");
	EXPECT_EQ(TRANS_Z_N(a).toString(), b.toString());
	
	//При нуле вылетает ошибка
	//a = ULongNumber("0");
	//b = NLongNumber("0");
	//EXPECT_EQ(MUL_ZM_Z(a), "zero is not natural number");
}

TEST(Z, ADD_ZZ_Z)
{
	LongNumber a("123");
	LongNumber b("456");
	EXPECT_EQ(ADD_ZZ_Z(a, b).toString(), "579");
	LongNumber c(23520), d(50856);
	EXPECT_EQ(ADD_ZZ_Z(c, d).toString(), "74376");
}

TEST(Z, DIV_ZZ_Z)
{
	LongNumber a = (LongNumber)("6");
	LongNumber b = (LongNumber)("-5");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-1");

	a = (LongNumber)("10");
	b = (LongNumber)("-5");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-2");

	a = (LongNumber)("20");
	b = (LongNumber)("-6");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-3");

	a = (LongNumber)("-20");
	b = (LongNumber)("6");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-4");

	a = (LongNumber)("100");
	b = (LongNumber)("-3");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-33");

	a = (LongNumber)("-100");
	b = (LongNumber)("3");
	EXPECT_EQ(DIV_ZZ_Z(a, b).toString(), "-34");
}

TEST(Z, MOD_ZZ_Z)
{
	LongNumber a = (LongNumber)("20");
	LongNumber b = (LongNumber)("6");
	EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "2");

	a = (LongNumber)("20");
	b = (LongNumber)("-6");
	EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "2");

	a = (LongNumber)("-20");
	b = (LongNumber)("6");
	EXPECT_EQ(MOD_ZZ_Z(a, b).toString(), "4");
}