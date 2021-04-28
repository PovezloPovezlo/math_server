#pragma once

#include <stdexcept>

namespace base {

	class NotImplementedException : public std::logic_error {
	public:
		[[nodiscard]] char const *what() const noexcept override;
	};

}
