#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "prog1.hpp"

// Part#1
TEST_CASE("Case #1-1 Part#1: Naive String Matching"){
    auto output = findMatches("abcdefghijk", "f");
    auto expected =  std::vector<unsigned>{5};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-2"){
    auto output = findMatches("aabbcdeebbcbcdbcde", "bcd");
    auto expected =  std::vector<unsigned>{3, 11, 14};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-3"){
    auto output = findMatches("ABAAABCDBBABCDDEBCABCABC", "ABC");
    auto expected =  std::vector<unsigned>{4, 10, 18, 21};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-4"){
    auto output = findMatches("aaaaaaaaa", "b");
    auto expected =  std::vector<unsigned>{};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-5"){
    auto output = findMatches("bbbbbbbbbbbb", "b");
    auto expected =  std::vector<unsigned>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-6"){
    auto output = findMatches("akls4hd4h*slk4h***(Dks", "4h*");
    auto expected =  std::vector<unsigned>{7, 13};
    REQUIRE(output == expected);
}

TEST_CASE("Case #1-7"){
    auto output = findMatches("abABababABABababAB", "ABab");
    auto expected =  std::vector<unsigned>{2, 10};
    REQUIRE(output == expected);
}
//--------------------------------------------------------------------------------------------
// Part#2
TEST_CASE("Case #2-1 Part#2: Weighted Interval Schedule"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input1.txt");
    auto expected = 8;
    REQUIRE(output == expected);
}

TEST_CASE("Case #2-2"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input2.txt");
    auto expected =  8;
    REQUIRE(output == expected);
}

TEST_CASE("Case #2-3"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input3.txt");
    auto expected =  50;
    REQUIRE(output == expected);
}

TEST_CASE("Case #2-4"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input4.txt");
    auto expected =  13;
    REQUIRE(output == expected);
}

TEST_CASE("Case #2-5"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input5.txt");
    auto expected =  20;
    REQUIRE(output == expected);
}

TEST_CASE("Case #2-6"){
    auto output = solveWeightedIntervalScheduling("/Users/alexoh/Desktop/Programming/input6.txt");
    auto expected =  7;
    REQUIRE(output == expected);
}
// Part#2 Helper Functions
TEST_CASE("Case Helper#1-1 Part#2: Find Values of P[i]"){
    auto output = findP(std::vector<int>{0, 1, 2, 6, 3, 9, 10}, std::vector<int>{0, 5, 7, 8, 11, 13, 14}, std::vector<int>{0, 2, 4, 4, 7, 2, 1});
    auto expected = std::vector<int>{0, 0, 0, 1, 0, 3, 3};
    REQUIRE(output == expected);
}

TEST_CASE("Case Helper#1-2"){
    auto output = findP(std::vector<int>{0, 1, 3, 0, 5, 7, 5}, std::vector<int>{0, 4, 5, 6, 7, 8, 9}, std::vector<int>{0, 3, 1, 6, 3, 1, 5});
    auto expected = std::vector<int>{0, 0, 0, 0, 1, 3, 1};
    REQUIRE(output == expected);
}

TEST_CASE("Case #Helper1-3"){
    auto output = findP(std::vector<int>{0, 2, 5, 5, 2, 1, 1, 11, 3, 6, 1}, std::vector<int>{0, 3, 7, 8, 8, 9, 11, 12, 13, 14, 15}, std::vector<int>{0, 2, 5, 3, 1, 2, 2, 1, 3, 4, 50});
    auto expected = std::vector<int>{0, 0, 1, 1, 0, 0, 0, 5, 0, 1, 0};
    REQUIRE(output == expected);
}

TEST_CASE("Case #Helper1-4"){
    auto output = findP(std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, std::vector<int>{0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}, std::vector<int>{0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
    auto expected = std::vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    REQUIRE(output == expected);
}

TEST_CASE("Case #Helper1-5"){
    auto output = findP(std::vector<int>{0, 0, 3, 1, 2, 8}, std::vector<int>{0, 3, 5, 7, 8, 9}, std::vector<int>{0, 10, 10, 10, 10, 10});
    auto expected = std::vector<int>{0, 0, 0, 0, 0, 3};
    REQUIRE(output == expected);
}

TEST_CASE("Case #Helper1-6"){
    auto output = findP(std::vector<int>{0, 1, 1, 2, 3}, std::vector<int>{0, 2, 2, 3, 4}, std::vector<int>{0, 4, 3, 1, 3});
    auto expected = std::vector<int>{0, 0, 0, 0, 1};
    REQUIRE(output == expected);
}
