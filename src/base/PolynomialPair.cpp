#include "PolynomialPair.h"
#include "RationalFraction.h"
#include "NotImplementedException.h"
#include <utility>
#include <module/n.h>

using namespace base;

PolynomialPair::PolynomialPair(size_t degree, RationalFraction value) : degree(degree), value(std::move(value)) {}

bool PolynomialPair::operator==(const PolynomialPair *p) const {
    return p->degree == this->degree;
}

bool PolynomialPairComparator::operator()(const PolynomialPair* lhs, const PolynomialPair* rhs) const {
    return lhs->degree < rhs->degree;
}

bool PolynomialPairComparator::operator()(const PolynomialPair *lhs, size_t rhs) const {
    return lhs->degree < rhs;
}

bool PolynomialPairComparator::operator()(size_t lhs, const PolynomialPair *rhs) const {
    return lhs < rhs->degree;
}
