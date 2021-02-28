#ifndef SETSGENERATOR_COMBINATIONS_H
#define SETSGENERATOR_COMBINATIONS_H
#include <exception>
#include <iostream>
#include "sets.h"


class CombinationsException: public std::exception {
private:
    std::string error;
public:
    explicit CombinationsException(std::string error);
    const char* what() const noexcept override;
};


template <typename TYPE>
void generateCombinations(const TYPE *set, int n, int k) {
    // Algorithm condition check: n >= k > 0
    if (n < 1) {
        throw CombinationsException("The cardinality of the input set must be greater than 0");
    }
    if (k > n || k < 1) {
        throw CombinationsException("The cardinality of the required subsets must be greater than 0 "
                                    "and not exceed the cardinality of the input set");
    }

    // Algorithm condition check: the set does not contain duplicate elements
    if (!isSet(set, n)) {
        throw SetException("The set should not contain duplicate elements");
    }

    TYPE* subset = new TYPE[k];
    int* g = new int[n + 1];
    int* p = new int[n + 1];
    int i, j, t, s;

    for (j = 0; j < k; ++j) {
        g[j] = 1;
        p[j] = j + 1;
    }
    for (j = k; j < n + 1; ++j) {
        g[j] = 0;
        p[j] = j + 1;
    }

    t = k;
    p[0] = k;
    i = -1;

    int num = 1;
    while (i != n) {
        // subset output
        for (s = 0, j = n - 1; j >= 0; --j) {
            if (g[j] == 1) {
                subset[s++] = set[n - j - 1];
            }
        }
        std::cout << num++ << ". ";
        printSet(subset, k);
        std::cout << std::endl;

        i = p[0];
        p[0] = p[i];
        p[i] = i + 1;

        if (g[i] == 1) {
            if (t != 0) {
                g[t - 1] = not g[t - 1];
            } else {
                g[i - 1] = not g[i - 1];
            }
            ++t;
        } else {
            if (t != 1) {
                g[t - 2] = not g[t - 2];
            } else {
                g[i - 1] = not g[i - 1];
            }
            --t;
        }

        g[i] = not g[i];

        if (t == i || t == 0) {
            ++t;
        } else {
            t -= g[i - 1];
            p[i - 1] = p[0];
            p[0] = (t == 0 ? i - 1 : t);
        }
    }

    delete[] subset;
    delete[] g;
    delete[] p;
}


#endif