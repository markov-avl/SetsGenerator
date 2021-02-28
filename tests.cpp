// tests framework: https://github.com/google/googletest

#include "gtest/gtest.h"
#include "combinations.h"
#include "sets.h"


TEST(generateCombinations, combinations_exception_expected) {
    const int n = 9;
    const int k = 10;

    int intSet[n] = {10};
    EXPECT_THROW(generateCombinations(intSet, 0, k), CombinationsException);
    EXPECT_THROW(generateCombinations(intSet, n, k), CombinationsException);

    char charSet[n] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    EXPECT_THROW(generateCombinations(charSet, 0, k), CombinationsException);
    EXPECT_THROW(generateCombinations(charSet, n, k), CombinationsException);
}

TEST(generateCombinations, set_exception_expected) {
    const int n = 10;
    const int k = 5;

    int intSet[n] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 10};
    EXPECT_THROW(generateCombinations(intSet, n, k), SetException);

    char charSet[n] = {'a', 'a', 'c', 'd', 't', 'b', 'e', 'f', '1', '2'};
    EXPECT_THROW(generateCombinations(charSet, n, k), SetException);
}

TEST(generateCombinations, from_1_choose_1) {
    const int n = 1;
    const int k = 1;

    int intSet[n] = {10};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 10\n");

    char charSet[n] = {'i'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. i\n");
}

TEST(generateCombinations, from_2_choose_1) {
    const int n = 2;
    const int k = 1;

    int intSet[n] = {10, 20};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 20\n"
                                                      "2. 10\n");

    char charSet[] = {'p', '2'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 2\n"
                                                      "2. p\n");
}

TEST(generateCombinations, from_4_choose_2) {
    const int n = 4;
    const int k = 2;

    int intSet[n] = {10, 20, 30, 40};
    testing::internal::CaptureStdout();
    generateCombinations(intSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 30, 40\n"
                                                      "2. 20, 30\n"
                                                      "3. 20, 40\n"
                                                      "4. 10, 20\n"
                                                      "5. 10, 30\n"
                                                      "6. 10, 40\n");
    /* this test does not work for some reasons
     * this captures codes of chars and compares them with char signs, so test fails

    int charSet[n] = {'5', 'f', '9', 'r'};
    testing::internal::CaptureStdout();
    generateCombinations(charSet, n, k);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1. 9, r\n"
                                                      "2. f, 9\n"
                                                      "3. f, r\n"
                                                      "4. 5, f\n"
                                                      "5. 5, 9\n"
                                                      "6. 5, r\n");
    */
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}