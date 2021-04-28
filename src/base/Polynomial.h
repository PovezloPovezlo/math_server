#pragma once

#include <vector>
#include "RationalFraction.h"

namespace base {

	class Polynomial {
	private:
		// coefficients[n] - получить коэффициент при n степени
		std::vector<RationalFraction> coefficients;

	public:

		explicit Polynomial(std::vector<RationalFraction> coefficients);
		explicit Polynomial(size_t size);

		[[nodiscard]] size_t degree() const;

		RationalFraction& operator[](size_t index);

		std::string toString();

	};

}
