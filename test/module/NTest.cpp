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