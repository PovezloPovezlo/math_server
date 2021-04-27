#include "LongNumberException.h"

using namespace base;

LongNumberException::LongNumberException(const char *reason) : reason(reason){}

LongNumberException::LongNumberException(const std::string& reason) : reason(reason.c_str()) {}

const char *LongNumberException::what() const noexcept {
	return reason;
}
