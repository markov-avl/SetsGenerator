// tests framework: https://github.com/google/googletest

#include "gtest/gtest.h"
#include "combinations.h"
#include "sets.h"


TEST(generateCombinations, combination_exception_expected) {
    const int N = 9;
    const int K = 10;

    int intSet[N] = {10};
    EXPECT_THROW(generateCombinations(intSet, 0, K), CombinationException);
    EXPECT_THROW(generateCombinations(intSet, N, K), CombinationException);

    char charSet[N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    EXPECT_THROW(generateCombinations(charSet, 0, K), CombinationException);
    EXPECT_THROW(generateCombinations(charSet, N, K), CombinationException);
}

TEST(generateCombinations, set_exception_expected) {
    const int N = 10;
    const int K = 5;

    int intSet[N] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 10};
    EXPECT_THROW(generateCombinations(intSet, N, K), SetException);

    char charSet[N] = {'a', 'a', 'c', 'd', 't', 'b', 'e', 'f', '1', '2'};
    EXPECT_THROW(generateCombinations(charSet, N, K), SetException);
}

TEST(generateCombinations, from_1_choose_1) {
    const int N = 1;
    const int K = 1;

    int intSet[N] = {10};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 10\n");

    char charSet[N] = {'i'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. i\n");
}

TEST(generateCombinations, from_2_choose_1) {
    const int N = 2;
    const int K = 1;

    int intSet[N] = {10, 20};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 20\n"
                                                      "2. 10\n");

    char charSet[N] = {'p', '2'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 2\n"
                                                      "2. p\n");
}

TEST(generateCombinations, from_4_choose_2) {
    const int N = 4;
    const int K = 2;

    int intSet[N] = {10, 20, 30, 40};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 30, 40\n"
                                                      "2. 20, 30\n"
                                                      "3. 20, 40\n"
                                                      "4. 10, 20\n"
                                                      "5. 10, 30\n"
                                                      "6. 10, 40\n");

    char charSet[N] = {'5', 'f', '9', '!'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, N, K);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 9, !\n"
                                                      "2. f, 9\n"
                                                      "3. f, !\n"
                                                      "4. 5, f\n"
                                                      "5. 5, 9\n"
                                                      "6. 5, !\n");
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}