#include "combinations.h"


CombinationException::CombinationException(std::string error) {
    this->error = std::move(error);
}

const char* CombinationException::what() const noexcept {
    return this->error.c_str();
}


