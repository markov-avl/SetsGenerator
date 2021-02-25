#ifndef SETSGENERATOR_SETS_H
#define SETSGENERATOR_SETS_H


class SetException: public std::exception {
private:
    std::string error;
public:
    explicit SetException(std::string error);
    const char* what() const noexcept override;
};


template <class TYPE>
bool isSet(const TYPE* set, int n) {
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

template <class TYPE>
void printSet(const TYPE* set, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << set[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
}


#endif
