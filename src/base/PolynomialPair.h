#pragma once

#include <base/ULongNumber.h>
#include <base/RationalFraction.h>

#include <utility>

namespace base {

	class PolynomialPair {
	public:
		size_t degree;
		RationalFraction value;

		PolynomialPair(size_t degree, RationalFraction value);

		bool operator ==(const PolynomialPair* p) const;

	};

    struct PolynomialPairComparator
    {
    public:
        //using is_transparent = void;//Can be anything, just needs to be defined.
        bool operator()(const PolynomialPair* lhs, const PolynomialPair* rhs) const;
        bool operator()(size_t lhs, const PolynomialPair* rhs) const;
        bool operator()(const PolynomialPair* lhs, size_t rhs) const;
    };

}
