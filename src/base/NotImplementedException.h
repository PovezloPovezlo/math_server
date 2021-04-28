#pragma once

#include <stdexcept>

namespace base {

	class NotImplementedException : public std::logic_error {
	public:
		NotImplementedException();

		[[nodiscard]] char const *what() const noexcept override;
	};

}
