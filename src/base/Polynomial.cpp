#include "Polynomial.h"

#include <utility>

using namespace base;

Polynomial::Polynomial(std::vector<RationalFraction> coefficients) : coefficients(std::move(coefficients)) {
	if(this->degree() > 0 && this->coefficients.back().numerator.toString() == "0"){ // todo заменить вызовом NZER_N_B
		throw BaseException("Polynomial can't have zero at last coefficient");
	}
}

Polynomial::Polynomial(size_t size) {
	for(int i = 0; i < size; ++i){
		coefficients.push_back(RationalFraction::empty());
	}
}

size_t Polynomial::degree() const {
	// гарантируется, что size >= 1, поэтому нет нужды проверять на 0
	return coefficients.size() - 1;
}

RationalFraction &Polynomial::operator[](size_t index) {
	return coefficients[index];
}

std::string Polynomial::toString() const {
	std::string result;
	auto j = degree();
	for(auto i = coefficients.rbegin(); i < (coefficients.rend()-1); ++i, --j){
		result += i->toString() + "*x^" + std::to_string(j) + " ";
	}

	result += coefficients[0].toString();

	return result;
}
