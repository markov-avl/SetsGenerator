#include <iostream>
#include "sets.h"


SetException::SetException(std::string error) {
    this->error = std::move(error);
}

const char* SetException::what() const noexcept {
    return this->error.c_str();
}