#pragma once

#include "RationalFraction.h"
#include <tsl/ordered_map.h>

namespace base {

	class Polynomial {
	public:
		// todo может стоит сделать двусвязным списком?
		tsl::ordered_map<std::string, RationalFraction> coefficients;

		explicit Polynomial(tsl::ordered_map<std::string, RationalFraction> coefficients);
		explicit Polynomial();

		[[nodiscard]] std::string toString() const;

	};

}
