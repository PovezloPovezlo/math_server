#pragma once

#include <vector>
#include "RationalFraction.h"

namespace base {

	class Polynomial {
	private:
		std::vector<RationalFraction> coefficients;

	public:

		explicit Polynomial(std::vector<RationalFraction> coefficients);
		explicit Polynomial(size_t size);

		[[nodiscard]] size_t degree() const;

	};

}
