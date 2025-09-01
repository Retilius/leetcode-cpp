#include "pch.h"
#include <vector>
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.


Example 1:


Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.
*/
using namespace std;
namespace leetcode_36 {
    class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
			// regarde si chaque ligne, colonne et bloc 3x3 est valide
			// chaque chiffre de 1 à 9 doit apparaître une seule fois par ligne, colonne et bloc
			// donc il y a 9 9 par ligne si il est déjà true alors return false
            bool ligne[9][9] = { false };
            bool col[9][9] = { false };
            bool bloc[9][9] = { false };
			int stop = 0;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++) {
                    if(board[i][j] != '.') {
                        int num = board[i][j] - '1'; // convertit le caractère en un index de 0 à 8
                        if(num == 4) {
							stop = 1;
						} 
                        int k = (i / 3) * 3 + j / 3; // calcule l'index du bloc 3x3
                        if (ligne[i][num] || col[j][num] || bloc[k][num]) {
                            return false; // le chiffre a déjà été vu dans la ligne, la colonne ou le bloc
                        }
                        ligne[i][num] = col[j][num] = bloc[k][num] = true; // marque le chiffre comme vu
					}
                }
            }
			return true; // toutes les lignes, colonnes et blocs sont valides

        }
    };
}
using Solution = leetcode_36::Solution;