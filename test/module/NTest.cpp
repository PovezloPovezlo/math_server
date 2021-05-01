#include <gtest/gtest.h>
#include <base/LongNumber.h>
#include <base/ULongNumber.h>
#include <base/NLongNumber.h>
#include <module/n.h>

using namespace base;
using namespace module;

// тесты

TEST(LongNumber, ADD_NN_N) {

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
		"345987981723987943857987129387"
		"283746283746823746823468273648"
		"213412831928379238474592873982"
		"129837293847923847918279387129"
		"120938723948719283912837918273"
		"345987981723987943857987129387"
		"283746283746823746823468273648"
		"213412831928379238474592873982"
		"129837293847923847918279387129"
		"120938723948719283912837918273"
		"345987981723987943857987129387"
		"283746283746823746823468273648"
		"213412831928379238474592873982"
		"129837293847923847918279387129"
		"120938723948719283912837918273"
	), 
		t2 = ULongNumber(
						"23429387462938746198273691827368761928"
						"63987126987612938761982761928376972311"
						"12931928379182739182739182739182739182"
						"23894729234872638476182763817263817263"
						"29384729384719287391827391827393248231"
						"63987126987612938761982761928376972311"
						"12931928379182739182739182739182739182"
						"23894729234872638476182763817263817263"
						"29384729384719287391827391827393248231"
						"63987126987612938761982761928376972311"
						"12931928379182739182739182739182739182"
						"23894729234872638476182763817263817263"
						"29384729384719287391827391827393248231"
						"63987126987612938761982761928376972311"
						"12931928379182739182739182739182739182"
						"23894729234872638476182763817263817263"
						"29384729384719287391827391827393248231"),
		r = ULongNumber(
			"2342938746293874619827369182736876192806398"
			"7126987612938761982761928376972311012931928"
			"3791827391827391827391827391820238947292348"
			"7263847618276381726381726302938472938471928"
			"7391827391827393248231064021725785785337556"
			"3685606413156751484757693966166509738654756"
			"6295259557111040313320382774662048916649320"
			"2056202054857323442285928674631314584666521"
			"6274137943331149693369267058407490577640006"
			"8564130661075386508601010398487331105846581"
			"6279475163612458606020057665187665181308771"
			"8583968131597866993202186770400583674470068"
			"0485281820056263322224725605729667875212600"
			"6207456387204080465932019947742188522270839"
			"7745557022965022964458232560195056580113405"
			"46675740231166504"
		);
	EXPECT_EQ(module::ADD_NN_N(t1, t2), r);
}

TEST(LongNumber, SUB_NN_N) {

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

	t1 = ULongNumber(100), t2 = ULongNumber(1), r = ULongNumber(9);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(10000), r = ULongNumber(9999);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);

	t1 = ULongNumber(
		"1673934601384569013847561038247601837465138067459"
		"6782354193678640183724650813745608374561034560256"
		"34875634786538475613084756013874560138475610384756"
	), t2 = ULongNumber(
		"2837462837468237462837468237460823746082346193876459"
		"3486759138745691387456093817465087136048576"
	), r = ULongNumber(
		"1673934601384569013847561038247601837465138067459678207"
		"04473948933599783670669218622921864263256369611104129977"
		"9336867393368557780742673388474336180"
	);
	EXPECT_EQ(module::SUB_NN_N(t1, t2), r);
}

TEST(LongNumber, MUL_ND_N) {

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

TEST(LongNumber, MUL_Nk_N) {

	ULongNumber t1(0), t2(0), r(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(1), r = ULongNumber(10);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(0), t2 = ULongNumber(1), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(1), t2 = ULongNumber(0), r = ULongNumber(1);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(9), t2 = ULongNumber(2), r = ULongNumber(900);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber("1239871298371263192678359273658173465081376"),
		t2 = ULongNumber(50), r = ULongNumber(
		"123987129837126319267835927365817346508137600000000000000000000000000000000000000000000000000"
	);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber("1239871298371263192678359273658173465081376"),
		t2 = ULongNumber(0), r = ULongNumber(
			"1239871298371263192678359273658173465081376"
		);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);

	t1 = ULongNumber(0),
		t2 = ULongNumber(1239878612), r = ULongNumber(0);
	EXPECT_EQ(module::MUL_Nk_N(t1, t2), r);
}

TEST(LongNumber, MUL_NN_N) {

	ULongNumber t1(0), t2(0), r(0);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	ULongNumber t1(1), t2(0), r(0);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	ULongNumber t1(1), t2(1), r(1);
	EXPECT_EQ(module::MUL_NN_N(t1, t2), r);

	ULongNumber t1(1), t2(10), r(10);
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
