#pragma once

#include <string>
#include <vector>

typedef unsigned char DIGIT;

namespace base {

	// Целое число
	class LongNumber {

	protected:
		std::vector<DIGIT> digits;
	public:
		bool isPositive;

		explicit LongNumber(std::string value);
		explicit LongNumber(size_t size, bool isPositive);
		explicit LongNumber(int value);

		[[nodiscard]] size_t length() const;
		[[nodiscard]] size_t lastElementIndex() const;

		DIGIT& operator[](size_t index);

		[[nodiscard]] std::string toString() const;

		static LongNumber empty();
		static LongNumber fromInt(int value);
	};

}
