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

TEST(N, ADD_NN_N) {
	ULongNumber t1(0), t2(0), r(0);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(0), t2 = ULongNumber(1), r = ULongNumber(1);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(1), t2 = ULongNumber(0), r = ULongNumber(1);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(1), t2 = ULongNumber(1), r = ULongNumber(2);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(9), t2 = ULongNumber(1), r = ULongNumber(10);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(9), t2 = ULongNumber(9), r = ULongNumber(18);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(99), t2 = ULongNumber(1), r = ULongNumber(100);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(99), t2 = ULongNumber(99), r = ULongNumber(198);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	t1 = ULongNumber(999), t2 = ULongNumber(999), r = ULongNumber(2000-2);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
	//this is fucking hardcore...
	t1 = ULongNumber(
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"

	), 
		t2 = ULongNumber(
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		"123123123123123123123123123123123123123123123123123123123123"
		),
		r = ULongNumber(
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
			"246246246246246246246246246246246246246246246246246246246246"
		);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
}

TEST(N, SUB_NN_N) {
	ULongNumber t1(0), t2(0), r(0);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(1), r = ULongNumber(0);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(0), t2 = ULongNumber(1), r = ULongNumber(1);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(9), t2 = ULongNumber(1), r = ULongNumber(8);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(9), r = ULongNumber(8);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber("100"), t2 = ULongNumber("1"), r = ULongNumber("99");
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(10000), r = ULongNumber(9999);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(
		"123123123123123123123123123123"
	), t2 = ULongNumber(
		"123123123123123123123123123123"
	), r = ULongNumber(
		"0"
	);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);
}

TEST(N, MUL_ND_N) {
	ULongNumber t1(0), r(0);
	DIGIT t2 = 0;
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = 0, r = ULongNumber(0);
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);

	t1 = ULongNumber(999), t2 = 0, r = ULongNumber(0);
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);

	t1 = ULongNumber(999), t2 = 2, r = ULongNumber(999*2);
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);

	t1 = ULongNumber(999), t2 = 9, r = ULongNumber(999*9);
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);

	t1 = ULongNumber(
		"1239871298371263192678359273658173465081376"
		"4058726340587634085762308476130485610384560"
		"1387456031847650138475601384756013847560138"
		"7456190384756913847561374659134765193476591"
		"2837462398746283476283746384284228476284648"
		"2462837462387462938716987469182736489172369"
		"478162342"
	), t2 = 9, r = ULongNumber(
		 "1115884168534136873410523346292356118573238"
		 "7652853706528870677186077628517437049346104"
		 "1248710428662885124628041246280412462804124"
		 "8710571346281222462805237193221288674128932"
		 "1553716158871655128655371745855805628656183"
		 "4216553716148716644845288722264462840255132"
		 "5303461078"
	);
	EXPECT_EQ(module::MUL_ND_N(t1, t2), r);
}

TEST(N, MUL_Nk_N) {
	ULongNumber t1(0);
	size_t t2(0);
	ULongNumber r(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = size_t(1), r = ULongNumber(10);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);		  
												  
	t1 = ULongNumber(0), t2 = size_t(1), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);		  
												  
	t1 = ULongNumber(1), t2 = size_t(0), r = ULongNumber(1);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);		 
												 
	t1 = ULongNumber(9), t2 = size_t(2), r = ULongNumber(900);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber("1239871298371263192678359273658173465081376"),
		t2 = size_t(50), r = ULongNumber(
		"123987129837126319267835927365817346508137600000000000000000000000000000000000000000000000000"
	);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber("1239871298371263192678359273658173465081376"),
		t2 = size_t(0), r = ULongNumber(
			"1239871298371263192678359273658173465081376"
		);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(0),
		t2 = size_t(100000), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

}

TEST(N, MUL_NN_N) {
	ULongNumber t1(0), t2(0), r(0);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(0), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(1), r = ULongNumber(1);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(10), r = ULongNumber(10);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber("34769842375093947602795057502"),
	t2 = ULongNumber("934764306743025843920574307342"),
	r = ULongNumber("32501607603318977089466611768694381335276525589084710779684");
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber("273453842375093947602795057502"),
	t2 = ULongNumber("278354664306743025843920574307342"),
	r = ULongNumber("76117152497708296792192449542441402109335276525589084710779684");
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	t1 = ULongNumber("273453842375093947602795057502"),
	t2 = ULongNumber(0), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);
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
