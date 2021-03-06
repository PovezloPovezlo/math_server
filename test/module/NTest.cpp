#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/n.h>
#include <string>

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
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(0), t2 = ULongNumber(1), r = ULongNumber(1);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(1), t2 = ULongNumber(0), r = ULongNumber(1);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(1), t2 = ULongNumber(1), r = ULongNumber(2);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(9), t2 = ULongNumber(1), r = ULongNumber(10);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(9), t2 = ULongNumber(9), r = ULongNumber(18);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(99), t2 = ULongNumber(1), r = ULongNumber(100);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(99), t2 = ULongNumber(99), r = ULongNumber(198);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
	t1 = ULongNumber(999), t2 = ULongNumber(999), r = ULongNumber(2000-2);
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());

	t1 = ULongNumber(914), t2 = ULongNumber(135), r = ULongNumber(779);
	//todo EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
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
	EXPECT_EQ(module::ADD_NN_N(t1, t2).toString(), r.toString());
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
		"1239871298371263192678359273658173465081376"
		"00000000000000000000000000000000000000000000000000"
	);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber("1239871298371263192678359273658173465081376"),
		t2 = size_t(0), r = ULongNumber(
			"1239871298371263192678359273658173465081376"
		);
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
	EXPECT_EQ(NZER_N_B(a), true);
	a = ULongNumber("3405053653600854343430");
	EXPECT_EQ(NZER_N_B(a), true);
	a = ULongNumber("0");
	EXPECT_EQ(NZER_N_B(a), false);
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

TEST(N, SUB_NDN_N) {
    ULongNumber t1 = ULongNumber("2476056797356347596392562367");
    ULongNumber t2 = ULongNumber("572376895736895");
    ULongNumber res = ULongNumber("2476056797353485711913877892");
    DIGIT k = 5;
    EXPECT_EQ(SUB_NDN_N(t1, k, t2), res);
    t1 = ULongNumber("619836423180240458169153");
    t2 = ULongNumber("56348765743658223469923");
    res = ULongNumber("0");
    k = 11;
    EXPECT_EQ(SUB_NDN_N(t1, k, t2), res);
    t1 = ULongNumber("2578387974963763587");
    t2 = ULongNumber("1896546596493659816589463572436592068923");
    k = 225; // тест выбрасывает ошибку, если вычитаемое больше уменьшаемого (чтобы тест не крашился, можно убрать нижнюю строку)
    //EXPECT_EQ(SUB_NDN_N(t1, k, t2), res);
}

TEST(N, DIV_NN_Dk) {
    ULongNumber t1 = ULongNumber("77894387680438047568");
    ULongNumber t2 = ULongNumber("135");
    ULongNumber res = ULongNumber("500000000000000000");
    auto digitres = 5;
    auto rankres = 17;
    EXPECT_EQ(DIV_NN_Dk(t1, t2).first, digitres);
    EXPECT_EQ(DIV_NN_Dk(t1, t2).second, rankres);
    t1 = ULongNumber("25266254736776");
    t2 = ULongNumber("1234567890634476375675757");
    //EXPECT_EQ(DIV_NN_Dk(t1, t2), res); - бросает ошибку, тк делитель больше делимого
    t1 = ULongNumber("25266254736776");
    t2 = ULongNumber("25266254736776");
    res = ULongNumber("1");
    digitres = 1;
    rankres = 0;
    EXPECT_EQ(DIV_NN_Dk(t1, t2).first, digitres);
    EXPECT_EQ(DIV_NN_Dk(t1, t2).second, rankres);
    t1 = ULongNumber("4532652364385340438578947957432569435");
    t2 = ULongNumber("0");
    //EXPECT_EQ(DIV_NN_Dk(t1, t2), res); //- бросает ошибку, тк делим на ноль
    t1 = ULongNumber("1000");
    t2 = ULongNumber("5");
    res = ULongNumber("200");
    digitres = 2;
    rankres = 2;
    EXPECT_EQ(DIV_NN_Dk(t1, t2).first, digitres);
    EXPECT_EQ(DIV_NN_Dk(t1, t2).second, rankres);
}

TEST(N, DIV_NN_N) {
	NLongNumber t1 = NLongNumber("10"), t2 = NLongNumber("2");
	ULongNumber res = ULongNumber("5");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());
	
	t1 = NLongNumber("100"), t2 = NLongNumber("5"), res = ULongNumber("20");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("11"), t2 = NLongNumber("5"), res = ULongNumber("2");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("15"), t2 = NLongNumber("5"), res = ULongNumber("3");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("16"), t2 = NLongNumber("5"), res = ULongNumber("3");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("101"), t2 = NLongNumber("1"), res = ULongNumber("101");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());


	t1 = NLongNumber("1119872938798719287398719831"), t2 = NLongNumber("519872"), res = ULongNumber("2154132053272188706833");
	EXPECT_EQ(DIV_NN_N(t1, t2).toString(), res.toString());
}

TEST(N, MOD_NN_N) {
	NLongNumber t1 = NLongNumber("10"), t2 = NLongNumber("2");
	ULongNumber res = ULongNumber("0");
	EXPECT_EQ(MOD_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("10"), t2 = NLongNumber("3"), res = ULongNumber("1");
	EXPECT_EQ(MOD_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("100"), t2 = NLongNumber("99"), res = ULongNumber("1");
	EXPECT_EQ(MOD_NN_N(t1, t2).toString(), res.toString());

	t1 = NLongNumber("19348793456987398676293847698762239487"), t2 = NLongNumber("23876827364876"), res = ULongNumber("4717636538795");
	EXPECT_EQ(MOD_NN_N(t1, t2).toString(), res.toString());
}

TEST(N, GCF_NN_N) {
	ULongNumber t1 = ULongNumber("6"), t2 = ULongNumber("9");
	ULongNumber res = ULongNumber("3");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber("1"), t2 = ULongNumber("0"); res = ULongNumber("1");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber("1"), t2 = ULongNumber("1"); res = ULongNumber("1");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber("15"), t2 = ULongNumber("5"); res = ULongNumber("5");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber("100"), t2 = ULongNumber("50"); res = ULongNumber("50");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber(
		"128756324958643234583538564738338658"
		"283756398586868686868634655938866369"
		"387458668663845765385346583863483856"),
	t2 = ULongNumber("1"); res = ULongNumber("1");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());

	t1 = ULongNumber(
		"32659237493987349324984656949235684659629698495643075097"
		"3409657079549546769573949867485929057067057057634964"),
	t2 = ULongNumber("5732894686594587632784454678568237456438655754");
	res = ULongNumber("22");
	EXPECT_EQ(GCF_NN_N(t1, t2).toString(), res.toString());
}

TEST (N, LCM_NN_N) {
    NLongNumber t1 = NLongNumber("293"), t2 = NLongNumber("677"), res = NLongNumber("198361");
    EXPECT_EQ(LCM_NN_N(t1, t2).toString(), res.toString());
    t1 = NLongNumber("100"), t2 = NLongNumber("5"), res = NLongNumber("100");
    EXPECT_EQ(LCM_NN_N(t1, t2).toString(), res.toString());
    t1 = NLongNumber("24"), t2 = NLongNumber("42"), res = NLongNumber("168");
    EXPECT_EQ(LCM_NN_N(t1, t2).toString(), res.toString());
}