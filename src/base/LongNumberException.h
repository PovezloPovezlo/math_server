#pragma once

#include <exception>
#include <string>

namespace base {

	struct LongNumberException : public std::exception {

		const char *reason;

		explicit LongNumberException(const char *reason);
		explicit LongNumberException(const std::string& reason);

		[[nodiscard]] const char *what() const noexcept override;

	};

}