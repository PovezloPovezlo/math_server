#pragma once

#include <vector>
#include "RationalFraction.h"

namespace base {

	class Polynomial {
	private:
		// coefficients[n] - получить коэффициент при n степени
		// todo возможно сделать через связный список (ну или по крайней мере не хранить нулевые элементы). А можно даже и map<>
		std::vector<RationalFraction> coefficients;

	public:

		explicit Polynomial(std::vector<RationalFraction> coefficients);
		explicit Polynomial(size_t size);

		[[nodiscard]] size_t degree() const;

		//todo заменить size_t на ULongNumber
		RationalFraction& operator[](size_t index);

		[[nodiscard]] std::string toString() const;

	};

}
