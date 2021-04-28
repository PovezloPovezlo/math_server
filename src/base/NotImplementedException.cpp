#include "NotImplementedException.h"

char const *base::NotImplementedException::what() const noexcept { return "Function not yet implemented."; }

base::NotImplementedException::NotImplementedException() : logic_error("Not implemented") {}