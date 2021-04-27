#pragma once

#include <string>
#include <vector>

typedef unsigned char DIGIT;

namespace base {

	class LongNumber {

	protected:
		std::vector<DIGIT> digits;
	public:
		bool isPositive;

		explicit LongNumber(std::string value);
		explicit LongNumber(size_t size, bool isPositive);

		[[nodiscard]] size_t length() const;
		[[nodiscard]] size_t lastElementIndex() const;

		DIGIT& operator[](size_t index);

		std::string toString();

		static LongNumber empty();
		static LongNumber fromInt(int value);
	};

}