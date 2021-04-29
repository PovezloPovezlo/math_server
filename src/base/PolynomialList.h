#pragma once

#include <base/ULongNumber.h>
#include <base/RationalFraction.h>

#include <utility>

namespace base {

	class PolynomialList {
	public:
		ULongNumber degree;
		RationalFraction value;
		PolynomialList* prev;
		PolynomialList* next;

		PolynomialList(ULongNumber degree, RationalFraction value) : degree(std::move(degree)), value(std::move(value)), prev(nullptr), next(nullptr) {}

		PolynomialList* lastElement();
		PolynomialList* addElement(PolynomialList* element);

		PolynomialList* operator [](const ULongNumber& index);

	};

}
