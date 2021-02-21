#include "combinations.h"

int main() {
    const int N = 6;
    const int K = 3;

    int set[N] {};
    generate_combinations(set, N, K);

    return 0;
}