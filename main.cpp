#include "combinations.h"

int main() {
    int k = 3;
    int set[] = {1, 2, 3, 4, 5, 9};

    int length = sizeof(set) / sizeof(set[0]);
    generate_combinations(set, length, k);

    return 0;
}