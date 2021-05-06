#pragma once

#include <string>
#include <vector>

typedef unsigned char DIGIT;

namespace base {

	// Целое число
	class LongNumber {

    public:
        std::vector<DIGIT> digits;
		bool isPositive;

		explicit LongNumber(std::string value);
		LongNumber(size_t size, bool isPositive);
		explicit LongNumber(int value);

		[[nodiscard]] size_t length() const;
		[[nodiscard]] size_t realLength() const;
		[[nodiscard]] size_t lastElementIndex() const;

		DIGIT& operator[](size_t index);
		bool operator ==(const LongNumber& number) const;
		bool operator !=(const LongNumber& number) const;

		bool isZero() const;

		[[nodiscard]] std::string toString();

		void deleteRedundantZeros();

		static LongNumber empty();
		static LongNumber fromInt(int value);
		static LongNumber fromInt(size_t value);
	};

}
