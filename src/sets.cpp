#include <iostream>
#include "sets.h"


SetException::SetException(std::string error) {
    this->error = std::move(error);
}

const char* SetException::what() const noexcept {
    return this->error.c_str();
}


// template <typename TYPE>
bool isSet(const int* set, int n) {
    int element;
    for (int i = 0; i < n - 1; ++i) {
        element = set[i];
        for (int j = i + 1; j < n; ++j) {
            if (element == set[j]) {
                return false;
            }
        }
    }
    return true;
}

// template <typename TYPE>
void printSet(const int* set, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << set[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
}