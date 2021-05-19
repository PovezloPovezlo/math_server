#include <gtest/gtest.h>
#include <base/RationalFraction.h>
#include <module/q.h>

using namespace base;
using namespace module;

// тесты
TEST(Q, INT_Q_B){
    RationalFraction a(LongNumber(1), NLongNumber(10));
    RationalFraction b(LongNumber(10), NLongNumber(1));
    RationalFraction c(LongNumber("-1000000000000000000000000000"), NLongNumber(1000));
    RationalFraction d(LongNumber("33333333333333333333333333333"), NLongNumber(3));
    //todo раскоментить когда функция будет готова EXPECT_EQ(INT_Q_B(a), false);
    EXPECT_EQ(INT_Q_B(b), true);
    EXPECT_EQ(INT_Q_B(c), true);
    EXPECT_EQ(INT_Q_B(d), true);
}

TEST(Q, ADD_QQ_Q) {
    ////todo раскоментить когда функция RED_Q_Q будет готова
    RationalFraction a(LongNumber(1), NLongNumber(4));
    RationalFraction b(LongNumber(1), NLongNumber(4));
    RationalFraction c(LongNumber(1), NLongNumber(2));
    EXPECT_EQ(ADD_QQ_Q(a, b).toString(), c.toString());

    a.numerator = LongNumber(120); a.denominator = NLongNumber(326);
    b.numerator = LongNumber(156); b.denominator = NLongNumber(196);
    c.numerator = LongNumber(9297); c.denominator = NLongNumber(7987);
    EXPECT_EQ(ADD_QQ_Q(a, c).toString(), c.toString());

    a.numerator = LongNumber(12410); a.denominator = NLongNumber(324566);
    b.numerator = LongNumber(15456); b.denominator = NLongNumber(178996);
    c.numerator = LongNumber(904729057); c.denominator = NLongNumber(7262001967);
    EXPECT_EQ(ADD_QQ_Q(a, c).toString(), c.toString());
}

TEST(Q, SUB_QQ_Q) {
    //todo раскоментить когда функция RED_Q_Q будет готова
    RationalFraction a(LongNumber(1), NLongNumber(2));
    RationalFraction b(LongNumber(1), NLongNumber(4));
    RationalFraction c(LongNumber(1), NLongNumber(4));
    EXPECT_EQ(SUB_QQ_Q(a, b).toString(), c.toString());

    a.numerator = LongNumber(120); a.denominator = NLongNumber(326);
    b.numerator = LongNumber(16); b.denominator = NLongNumber(196);
    c.numerator = LongNumber(2288); c.denominator = NLongNumber(7987);
    EXPECT_EQ(SUB_QQ_Q(a, c).toString(), c.toString());

    a.numerator = LongNumber(12410); a.denominator = NLongNumber(324566);
    b.numerator = LongNumber(1556); b.denominator = NLongNumber(178996);
    c.numerator = LongNumber(214539458); c.denominator = NLongNumber(7262001967);
    EXPECT_EQ(SUB_QQ_Q(a, c).toString(), c.toString());
}

TEST(Q, RED_Q_Q){
    RationalFraction a(LongNumber(-15), NLongNumber(25));
    RationalFraction b(LongNumber(-3), NLongNumber(5));

    RationalFraction c(LongNumber(16), NLongNumber(24));
    RationalFraction d(LongNumber(2), NLongNumber(3));

    EXPECT_EQ(RED_Q_Q(a).toString(), b.toString());
    EXPECT_EQ(RED_Q_Q(c).toString(), d.toString());

    RationalFraction k(LongNumber(-45), NLongNumber(5));
    EXPECT_EQ(RED_Q_Q(k).toString(), "-9");
}
