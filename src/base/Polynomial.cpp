#include "Polynomial.h"

#include <utility>

using namespace base;

Polynomial::Polynomial(std::vector<RationalFraction> coefficients) : coefficients(std::move(coefficients)) {}

size_t Polynomial::degree() const {
	return coefficients.size();
}
