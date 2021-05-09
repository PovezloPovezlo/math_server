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