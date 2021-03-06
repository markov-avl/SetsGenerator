#ifndef SETSGENERATOR_SETS_H
#define SETSGENERATOR_SETS_H


class SetException: public std::exception {
private:
    std::string error;
public:
    explicit SetException(std::string error);
    const char* what() const noexcept override;
};


template <typename TYPE>
bool isSet(const TYPE* set, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (set[i] == set[j]) {
                return false;
            }
        }
    }
    return true;
}

template <typename TYPE>
void printSet(const TYPE* set, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << set[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
}


#endif
