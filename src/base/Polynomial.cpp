#include "Polynomial.h"

#include <utility>

using namespace base;

Polynomial::Polynomial(std::vector<RationalFraction> coefficients) : coefficients(std::move(coefficients)) {}

size_t Polynomial::degree() const {
	// гарантируется, что size >= 1, поэтому нет нужды проверять на 0
	return coefficients.size() - 1;
}
