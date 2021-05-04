#pragma once

#include "RationalFraction.h"
#include "PolynomialPair.h"
#include <set>

namespace base {

    typedef std::set<PolynomialPair*, PolynomialPairComparator> PolynomialSet;

	class Polynomial {
	public:
        PolynomialSet coefficients;

		explicit Polynomial(PolynomialSet& coefficients);
		explicit Polynomial();

        PolynomialPair* firstElement();
        PolynomialPair* lastElement();
        void addElement(PolynomialPair* element);

        PolynomialPair* get(size_t index);
        RationalFraction getCoefficient(size_t index);

        void set(size_t index, RationalFraction& val);
        void remove(size_t index);

		std::string toString();
    };

}
