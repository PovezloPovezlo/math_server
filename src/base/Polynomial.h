#pragma once

#include "RationalFraction.h"
#include "PolynomialList.h"
#include <list>

namespace base {

	class Polynomial {
	public:
		PolynomialList* coefficients;
		//PolynomialList* coefficientsLastElement; todo может понадобится сделать?

		explicit Polynomial(PolynomialList* coefficients);
		explicit Polynomial();

		[[nodiscard]] std::string toString() const;

	};

}
