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