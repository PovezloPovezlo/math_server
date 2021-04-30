#include <gtest/gtest.h>
#include <base/Polynomial.h>

TEST(Polynomial, inputCheck){
	return; //todo

	tsl::ordered_map<std::string, base::RationalFraction> coefficients = {
			{"0", (base::RationalFraction)1},
			{"1", base::RationalFraction::fromTwoInt(6, 5)},
			{"2", (base::RationalFraction)0}
	};

	try {
		base::Polynomial p(coefficients);
		FAIL() << "Polynomial should't have zero at last coefficient";
	}catch(base::BaseException &exception){
		SUCCEED();
	}
}

TEST(Polynomial, toString){
	return; //todo
	tsl::ordered_map<std::string, base::RationalFraction> coefficients = {
			{"0", (base::RationalFraction)1},
			{"1", base::RationalFraction::fromTwoInt(6, 5)},
			{"2", (base::RationalFraction)1}
	};

	base::Polynomial p(coefficients);

	EXPECT_EQ(p.toString(), "1*x^2 6/5*x^1 4");
}