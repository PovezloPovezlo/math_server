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
    //EXPECT_EQ(INT_Q_B(b), true);
    //EXPECT_EQ(INT_Q_B(c), true);
    //EXPECT_EQ(INT_Q_B(d), true);
}

TEST(Q, RED_Q_Q){
    RationalFraction a(LongNumber(-15), NLongNumber(25));
    RationalFraction b(LongNumber(-3), NLongNumber(5));

    RationalFraction c(LongNumber(16), NLongNumber(24));
    RationalFraction d(LongNumber(2), NLongNumber(3));

    EXPECT_EQ(RED_Q_Q(a), b);
    EXPECT_EQ(RED_Q_Q(c), d);


}


