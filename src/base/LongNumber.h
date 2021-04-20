//
// Created by NolikTop on 20.04.2021.
//

#pragma once

#include <string>

typedef unsigned char DIGIT;

namespace base {

	class LongNumber {
	public:
		std::string data;
		bool isPositive;

		explicit LongNumber(std::string value);

		[[nodiscard]] size_t length() const;

		DIGIT getDigitAt(size_t pos);
		DIGIT getDigitFromEndAt(size_t pos);

	};

}