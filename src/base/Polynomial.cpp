#include "Polynomial.h"
#include <module/P/p.h>
#include <module/N/n.h>
#include <module/Z/z.h>
#include <utility>

using namespace base;

Polynomial::Polynomial(tsl::ordered_map<std::string, RationalFraction> coefficients) : coefficients(std::move(coefficients)) {
	if(module::NZER_N_B(module::DEG_P_N(*this)) && module::POZ_Z_D(this->coefficients.back().second.numerator) == 0){
		throw BaseException("Polynomial can't have zero at last coefficient");
	}
}

Polynomial::Polynomial() = default;

std::string Polynomial::toString() const {
	std::string result;
	const auto one = NLongNumber::fromInt(1);
	auto j = module::DEG_P_N(*this);
	for(auto i = coefficients.rbegin(); i < coefficients.rend(); ++i, j = module::SUB_NN_N(j, one)){
		result += i->second.toString() + "*x^" + j.toString() + " ";
	}

	return result;
}
