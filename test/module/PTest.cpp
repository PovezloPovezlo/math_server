#include <gtest/gtest.h>
#include <base/Polynomial.h>
#include <module/p.h>

using namespace base;
using namespace module;

// тесты

TEST(P, DER_P_P){
    Polynomial a;
    a.addElement(0, (RationalFraction)4);
    a.addElement(1, (RationalFraction)5); 
    a.addElement(2, (RationalFraction)6);
    EXPECT_EQ(DER_P_P(a).toString(), "12*x^1 5");

    Polynomial p;
    p.addElement(2, (RationalFraction)3);
    p.addElement(3, (RationalFraction)4);
    p.addElement(4, (RationalFraction)5);
    EXPECT_EQ(DER_P_P(p).toString(), "20*x^3 12*x^2 6*x^1");
  
    Polynomial p2;
    p2.addElement(0, (RationalFraction)5);
    EXPECT_EQ(DER_P_P(p2).toString(), "0");
}

TEST(P, GCF_PP_P){
	return; // todo MOD_PP_P еще не сделан
    Polynomial a;
    a.addElement(0, (RationalFraction)3);
    a.addElement(1, (RationalFraction)6);
    a.addElement(2, (RationalFraction)2);
    a.addElement(3, (RationalFraction)3);
    a.addElement(4, (RationalFraction)4);

    Polynomial b;
    b.addElement(0, (RationalFraction)3);
    b.addElement(1, (RationalFraction)6);
    b.addElement(2, (RationalFraction)5);
    b.addElement(3, (RationalFraction)2);
    auto res1 = GCF_PP_P(a, b);

    EXPECT_EQ(res1.toString(), "x 1");

    Polynomial a1, b1;
    a1.addElement(0, RationalFraction::fromTwoInt(1,2));
    a1.addElement(1, RationalFraction::fromTwoInt(3,1));
    a1.addElement(2, RationalFraction::fromTwoInt(7,8));
    a1.addElement(3, RationalFraction::fromTwoInt(2,3));
    a1.addElement(4, RationalFraction::fromTwoInt(5,4));

    b1.addElement(0, RationalFraction::fromTwoInt(4,9));
    b1.addElement(1, RationalFraction::fromTwoInt(1,1));
    b1.addElement(2, RationalFraction::fromTwoInt(2,5));
    auto res2 = GCF_PP_P(a1,b1);

    EXPECT_EQ(res2.toString(), "1/360");

    auto res3 = GCF_PP_P(a,b1);

    EXPECT_EQ(res3.toString(), "1/45");
}

TEST(P, MUL_PQ_P){
    Polynomial a;
    a.addElement(1, (RationalFraction)1);
    a.addElement(2, (RationalFraction)10);
    a.addElement(3, RationalFraction::fromTwoInt(5,2));

    auto b = RationalFraction::fromInt(2);
    auto res1 = MUL_PQ_P(a, b);

    EXPECT_EQ(res1.toString(), "10/2*x^3 20*x^2 2*x^1");
}