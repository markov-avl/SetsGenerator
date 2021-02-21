#ifndef SETSGENERATOR_COMBINATIONS_H
#define SETSGENERATOR_COMBINATIONS_H
#include <exception>
#include <iostream>


class CombinationsException: public std::exception {
private:
    std::string error;
public:
    explicit CombinationsException(std::string error);
    const char* what() const noexcept override;
};


template <typename TYPE>
void generate_combinations(TYPE* set, int n, int k);


#endif