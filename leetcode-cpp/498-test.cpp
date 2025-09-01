#include "pch.h"
#include <gtest/gtest.h>
#include "498.cpp"

using namespace leetcode_498;

namespace leetcode_498_test
{
    class DiagonalOrderTest :public ::testing::TestWithParam<tuple<vector<vector<int>> , vector<int>>> {};

    TEST_P(DiagonalOrderTest, DiagonalOrder)
    {
        // arrange
        Solution solution{};
        auto const& param = GetParam();
        auto nums = std::get<0>(param);
        auto expectedResult = std::get<1>(param);

        // act
        auto result = solution.findDiagonalOrder(nums);

        // assert
        EXPECT_EQ(result, expectedResult);
    }

    INSTANTIATE_TEST_CASE_P(
        DiagonalOrder,
        DiagonalOrderTest,
        ::testing::Values(
            // Example 1
            std::make_tuple(
                vector<vector<int>>{ {1, 2, 3}, { 4,5,6 }, { 7,8,9 } },
                vector<int>{ 1, 2, 4, 7, 5, 3, 6, 8, 9 }
            ),
            // Example 2
            std::make_tuple(
                vector<vector<int>>{ {1, 2}, { 3,4 } },
                vector<int>{ 1, 2, 3, 4 }
            ),
            // Single element
            std::make_tuple(
                vector<vector<int>>{ {42} },
                vector<int>{ 42 }
            ),
            // Single row
            std::make_tuple(
                vector<vector<int>>{ {1, 2, 3, 4} },
                vector<int>{ 1, 2, 3, 4 }
            ),
            // Single column
            std::make_tuple(
                vector<vector<int>>{ {1}, { 2 }, { 3 }, { 4 } },
                vector<int>{ 1, 2, 3, 4 }
            ),
            // Empty matrix
            std::make_tuple(
                vector<vector<int>>{},
                vector<int>{}
            ),
            // Rectangular tall
            std::make_tuple(
                vector<vector<int>>{ {1, 2}, { 3,4 }, { 5,6 } },
                vector<int>{ 1, 2, 3, 5, 4, 6 }
            ),
            // Rectangular wide
            std::make_tuple(
                vector<vector<int>>{ {1, 2, 3, 4}, { 5,6,7,8 } },
                vector<int>{ 1, 2, 5, 6, 3, 4, 7, 8 }
            ),
            // Negative numbers
            std::make_tuple(
                vector<vector<int>>{ {-1, -2}, { -3,-4 } },
                vector<int>{ -1, -2, -3, -4 }
            ),
            // Large 3x4 matrix
            std::make_tuple(
                vector<vector<int>>{ {1, 2, 3, 4}, { 5,6,7,8 }, { 9,10,11,12 } },
                vector<int>{ 1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12 }
            )
        )
    );
}
