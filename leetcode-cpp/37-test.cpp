#include "pch.h"
#include <gtest/gtest.h>
#include "37.cpp"

using namespace leetcode_37;

namespace leetcode_37_test
{
    class DiagonalOrderTest :public ::testing::TestWithParam<tuple<vector<vector<char>>, vector<vector<char>>>> {};

    TEST_P(DiagonalOrderTest, DiagonalOrder)
    {
        // arrange
        Solution solution{};
        auto const& param = GetParam();
        auto nums = std::get<0>(param);
        auto expectedResult = std::get<1>(param);

        // act
        solution.solveSudoku(nums);
        vector<vector<char>> result = nums;

        // assert
        EXPECT_EQ(result, expectedResult);
    }

    INSTANTIATE_TEST_CASE_P(
        DiagonalOrder,
        DiagonalOrderTest,
        ::testing::Values(std::make_tuple(
            vector<vector<char>>{ {'a'} },
            vector<vector<char>>{ {'a'} })
        )
    );
}