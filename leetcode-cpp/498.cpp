/* Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

        Example 1:

        Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,2,4,7,5,3,6,8,9]
        Example 2:

        Input: mat = [[1,2],[3,4]]
        Output: [1,2,3,4]

        Constraints:

        m == mat.length
        n == mat[i].length
        1 <= m, n <= 104
        1 <= m * n <= 104
        -105 <= mat[i][j] <= 105 */
#include "pch.h"
#include <vector>

using namespace std;
namespace leetcode_498 {
    class Solution {
    public:
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            if (mat.empty() || mat[0].empty()) return {};
            int m = mat.size();
            int n = mat[0].size();
            vector<int> result;
            result.reserve(m * n);
            for (int i = 0; i < m + n - 1; i++) {
                int a = i < m ? i : m - 1;
                int b = i < n ? 0 : i - n + 1;
                if (i % 2 == 0) {
                    for (int j = a; j >= b; --j) {
                        result.push_back(mat[j][i - j]);
                    }
                }
                else {
                    for (int j = b; j <= a; ++j) {
                        result.push_back(mat[j][i - j]);
                    }
                }

            }
            return result;

        }
    };
}
using Solution = leetcode_498::Solution;
// tjrs un problème de mémoire