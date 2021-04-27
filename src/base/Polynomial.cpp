#include "Polynomial.h"

#include <utility>

using namespace base;

Polynomial::Polynomial(std::vector<RationalFraction> coefficients) : coefficients(std::move(coefficients)) {}

Polynomial::Polynomial(size_t size) {
	for(int i = 0; i < size; ++i){
		coefficients.push_back(RationalFraction::empty());
	}
}

size_t Polynomial::degree() const {
	// гарантируется, что size >= 1, поэтому нет нужды проверять на 0
	return coefficients.size() - 1;
}
