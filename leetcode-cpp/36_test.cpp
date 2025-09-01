#include "pch.h"
#include <gtest/gtest.h>
#include "36.cpp"

using namespace leetcode_36;

namespace leetcode_36_test
{
    class Sudoku :public ::testing::TestWithParam<tuple<vector<vector<char>>, bool>> {};

    TEST_P(Sudoku, DiagonalOrder)
    {
        // arrange
        Solution solution{};
        auto const& param = GetParam();
        auto nums = std::get<0>(param);
        auto expectedResult = std::get<1>(param);

        // act
        
        bool result = solution.isValidSudoku(nums);

        // assert
        EXPECT_EQ(result, expectedResult);
    }
    INSTANTIATE_TEST_CASE_P(
        DiagonalOrder,
        Sudoku,
        ::testing::Values(
            std::make_tuple(
                vector<vector<char>> { {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
                                    , { '6', '.', '.', '1', '9', '5', '.', '.', '.' }
                                    , { '.', '9', '8', '.', '.', '.', '.', '6', '.' }
                                    , { '8', '.', '.', '.', '6', '.', '.', '.', '3' }
                                    , { '4', '.', '.', '8', '.', '3', '.', '.', '1' }
                                    , { '7', '.', '.', '.', '2', '.', '.', '.', '6' }
                                    , { '.', '6', '.', '.', '.', '.', '2', '8', '.' }
                                    , { '.', '.', '.', '4', '1', '9', '.', '.', '5' }
                                    , { '.', '.', '.', '.', '8', '.', '.', '7', '9' }},
                true
            ),
            std::make_tuple(
                vector<vector<char>> { {'.','.','4','.','.','.','6','3','.'}
                                     , {'.','.','.','.','.','.','.','.','.'}
                                     , {'5','.','.','.','.','.','.','9','.'}
                                     , {'.','.','.','5','6','.','.','.','.'}
                                     , {'4','.','3','.','.','.','.','.','1'}
                                     , {'.','.','.','7','.','.','.','.','.'}
                                     , {'.','.','.','5','.','.','.','.','.'}
                                     , {'.','.','.','.','.','.','.','.','.'}
                                     , {'.','.','.','.','.','.','.','.','.'}},
                false
            )
        )
    
    );
}