#include "BaseException.h"

using namespace base;

BaseException::BaseException(const char *reason) : reason(reason){}

BaseException::BaseException(const std::string& reason) : reason(reason.c_str()) {}

const char *BaseException::what() const noexcept {
	return reason;
}
