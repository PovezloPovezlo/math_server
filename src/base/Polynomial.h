#pragma once

#include "RationalFraction.h"
#include "PolynomialList.h"
#include <list>

namespace base {

	class Polynomial {
	public:
		PolynomialList coefficients;

		explicit Polynomial(PolynomialList coefficients);
		explicit Polynomial();

		[[nodiscard]] std::string toString() const;

	};

}
