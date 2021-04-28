#include <gtest/gtest.h>
#include <base/Polynomial.h>

TEST(Polynomial, inputCheck){
	std::vector<base::RationalFraction> coefficients;
	coefficients.push_back((base::RationalFraction)4);
	coefficients.push_back((base::RationalFraction)6);
	coefficients.push_back((base::RationalFraction)0);

	try {
		base::Polynomial p(coefficients);
		FAIL() << "Polynomial should't have zero at last coefficient";
	}catch(base::BaseException &exception){
		SUCCEED();
	}
}

TEST(Polynomial, toString){
	std::vector<base::RationalFraction> coefficients;
	coefficients.push_back((base::RationalFraction)4);
	coefficients.push_back(base::RationalFraction::fromTwoInt(6, 5));
	coefficients.push_back((base::RationalFraction)1);

	base::Polynomial p(coefficients);

	EXPECT_EQ(p.toString(), "1*x^2 6/5*x^1 4");
}