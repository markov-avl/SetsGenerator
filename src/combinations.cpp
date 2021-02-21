#include "combinations.h"
#include "sets.h"


CombinationsException::CombinationsException(std::string error) {
    this->error = std::move(error);
}

const char* CombinationsException::what() const noexcept {
    return this->error.c_str();
}


template <typename TYPE>
void generate_combinations(TYPE* set, int n, int k) {

    // Algorithm condition check: n >= k > 0
    if (n < 1) {
        throw CombinationsException("The cardinality of the input set must be greater than 0");
    }
    if (k > n || k < 1) {
        throw CombinationsException("The cardinality of the required subsets must be greater than 0 "
                                    "and not exceed the cardinality of the input set");
    }

    // Algorithm condition check: the set does not contain duplicate elements
    if (!isSet<TYPE>(set, n)) {
        throw SetException("The set should not contain duplicate elements");
    }

//    int* x = new int[k];
//    int* min = new int[k];
//    int* max = new int[k];
//    int i, j;
//
//    for (j = 0; j < k; ++j) {
//        min[j] = k - j;
//        max[j] = n - j;
//        x[j] = min[j];
//    }
//
//    i = 0;
//    while (i < k) {
//        printSet<int*>(x, k);
//        std::cout << std::endl;
//        i = 0;
//        while (i < k && x[i] == max[i]) {
//            ++i;
//        }
//        if (i < k) {
//            ++x[i];
//        }
//        for (j = i - 1; j >= 0; --j) {
//            min[j] = x[j + 1] + 1;
//            x[j] = min[j];
//        }
//    }
}