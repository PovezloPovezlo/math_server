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
    EXPECT_EQ(MUL_ZZ_Z(a, b), LongNumber("24691358024691358024691358024641975308641975308641975308642"));
    EXPECT_EQ(MUL_ZZ_Z(b, c), LongNumber("-24691358024691358024691358024641975308641975308641975308642"));
    EXPECT_EQ(MUL_ZZ_Z(a, k), LongNumber("333333333333333333333333333333"));
    EXPECT_EQ(MUL_ZZ_Z(c, k), LongNumber("-333333333333333333333333333333"));
}

TEST(Z, ABS_Z_N)
{
	LongNumber a("36454362134243");
	ULongNumber b("36454362134243");
	EXPECT_EQ(ABS_Z_N(a), b);

	a = LongNumber("-54343545543");
	b= ULongNumber("54343545543");
	EXPECT_EQ(ABS_Z_N(a), b);

	a = LongNumber("0");
	b = ULongNumber("0");
	EXPECT_EQ(ABS_Z_N(a), b);
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
	EXPECT_EQ(MUL_ZM_Z(a), b);

	a = LongNumber("-46746574567746647");
	b = LongNumber("46746574567746647");
	EXPECT_EQ(MUL_ZM_Z(a), b);

	a = LongNumber("0");
	b = LongNumber("0");
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

	a = NLongNumber("4");
	b = LongNumber("4");
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

	a = ULongNumber("3");
	b = NLongNumber("3");
	EXPECT_EQ(TRANS_Z_N(a), b);
	
	//При нуле вылетает ошибка
	//a = ULongNumber("0");
	//b = NLongNumber("0");
	//EXPECT_EQ(MUL_ZM_Z(a), "zero is not natural number"); 


}
