#include <iostream>
#include "sets.h"


SetException::SetException(std::string error) {
    this->error = std::move(error);
}

const char* SetException::what() const noexcept {
    return this->error.c_str();
}


template <typename TYPE>
bool isSet(TYPE* set, int n) {
    TYPE element;
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

template <typename TYPE>
void printSet(TYPE* set, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << (i < n - 1 ? set[i] << ", " : set[i]);
    }
}