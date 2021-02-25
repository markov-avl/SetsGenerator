#include "combinations.h"

int main() {
    int k = 4;
    char set[] = {1, 2, 3, 4, 5, 9};

    int length = sizeof(set) / sizeof(set[0]);
    generateCombinations(set, length, k);

    return 0;
}