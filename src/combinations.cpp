#include "combinations.h"


CombinationsException::CombinationsException(std::string error) {
    this->error = std::move(error);
}

const char* CombinationsException::what() const noexcept {
    return this->error.c_str();
}


