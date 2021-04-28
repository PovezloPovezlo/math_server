#pragma once

#include <exception>
#include <string>

namespace base {

	struct BaseException : public std::exception {

		const char *reason;

		explicit BaseException(const char *reason);
		explicit BaseException(const std::string& reason);

		[[nodiscard]] const char *what() const noexcept override;

	};

}