//
// Created by NolikTop on 20.04.2021.
//

#pragma once

#include <string>
#include <vector>

typedef unsigned char DIGIT;

namespace base {

	class LongNumber {
	public:
		std::vector<DIGIT> digits;
		bool isPositive;

		explicit LongNumber(std::string value);

		[[nodiscard]] size_t length() const;
		[[nodiscard]] size_t lastElementIndex() const;

		DIGIT& operator[](size_t index);

		std::string toString();

		static LongNumber empty();
	};

}