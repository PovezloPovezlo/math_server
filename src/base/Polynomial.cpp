#include "Polynomial.h"
#include <module/p.h>
#include <module/n.h>
#include <module/z.h>
#include <utility>

using namespace base;

Polynomial::Polynomial(PolynomialList* coefficients) : coefficients(coefficients) {
    // чистка списка коэффициентов от нулевых (потому что их нет смысла хранить)

    for(auto i = coefficients; i != nullptr; i = i->next){
        if(i->value)
    }

	if(module::NZER_N_B(module::DEG_P_N(*this)) && module::POZ_Z_D(this->coefficients.back().second.numerator) == 0){
		throw BaseException("Polynomial can't have zero at last coefficient");
	}
}

Polynomial::Polynomial(): coefficients(new PolynomialList(ULongNumber::empty(), RationalFraction::empty())){}

std::string Polynomial::toString() const {
	std::string result;
	const auto one = NLongNumber::fromInt(1);
	auto j = module::DEG_P_N(*this);
	for(auto i = coefficients.rbegin(); i < coefficients.rend(); ++i, j = module::SUB_NN_N(j, one)){
		result += i->second.toString() + "*x^" + j.toString() + " ";
	}

	return result;
}