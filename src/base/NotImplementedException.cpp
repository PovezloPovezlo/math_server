#include "NotImplementedException.h"

char const *base::NotImplementedException::what() const noexcept { return "Function not yet implemented."; }
