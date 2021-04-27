//
// Created by NolikTop on 27.04.2021.
//


#pragma once

#include <vector>
#include "RationalFraction.h"

namespace base {

	class Polynomial {
	public:
		std::vector<RationalFraction> coefficients;

		explicit Polynomial(std::vector<RationalFraction> coefficients);

		[[nodiscard]] size_t degree() const;

	};

}
