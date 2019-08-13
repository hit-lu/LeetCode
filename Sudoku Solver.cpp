// 2019/08/12   Backtracking Method
// Problem : solve the sudoku with unique solution
// Input :  [ 5   3   .   .   7   .   .   .   . ] 
//          [ 6   .   .   1   9   5   .   .   . ] 
//          [ .   9   8   .   .   .   .   6   . ] 
//          [ 8   .   .   .   6   .   .   .   3 ] 
//          [ 4   .   .   8   .   3   .   .   1 ] 
//          [ 7   .   .   .   2   .   .   .   6 ] 
//          [ .   6   .   .   .   .   2   8   . ] 
//          [ .   .   .   4   1   9   .   .   5 ] 
//          [ .   .   .   .   8   .   .   7   9 ]
// Output:  [ 5   3   4   6   7   8   9   1   2 ] 
//          [ 6   7   2   1   9   5   3   4   8 ] 
//          [ 1   9   8   3   4   2   5   6   7 ] 
//          [ 8   5   9   7   6   1   4   2   3 ] 
//          [ 4   2   6   8   5   3   7   9   1 ] 
//          [ 7   1   3   9   2   4   8   5   6 ] 
//          [ 9   6   1   5   3   7   2   8   4 ] 
//          [ 2   8   7   4   1   9   6   3   5 ] 
//          [ 3   4   5   2   8   6   1   7   9 ]
#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Table;
typedef vector<vector<bool>> Check;
typedef vector<vector<vector<bool>>> LCheck;        // larger check table
class Solution 
{
	public:
		void solveSudoku(Table& board) 
		{
			const int SudokuSize = board.size();
			// check whether element in 1~9 is used or not 
			LCheck boxUsed(SudokuSize, Check(SudokuSize, vector<bool>(9, false)));
			Check colUsed(SudokuSize, vector<bool>(9, false));
			Check rowUsed(SudokuSize, vector<bool>(9, false));

			for (int i = 0; i < SudokuSize; i++)
			{
				for (int j = 0; j < SudokuSize; j++)
				{
					if (board[i][j] != '.')
					{
						int sequence = board[i][j] - '0' - 1;
						boxUsed[i / 3][j / 3][sequence] = true;
						rowUsed[i][sequence] = true;
						colUsed[j][sequence] = true;
					}
				}
			}
			fullinSudoku(board, rowUsed, colUsed, boxUsed, 0, 0);

		}

		bool fullinSudoku(Table& board, Check& rowUsed, Check& colUsed, LCheck& boxUsed, int row, int col)
		{
			if (col == board[0].size())
			{
				col = 0;
				row++;
				if (row == board.size())
				{
					return true;
				}
			}

			if (board[row][col] == '.')
			{
				for (int sequence = 0; sequence < 9; sequence++)
				{
					bool noUsed = rowUsed[row][sequence] | colUsed[col][sequence] | boxUsed[row / 3][col / 3][sequence];
					if (noUsed == false)
					{
						rowUsed[row][sequence] = true;
						colUsed[col][sequence] = true;
						boxUsed[row / 3][col / 3][sequence] = true;

						board[row][col] = sequence + '0' + 1;
						if (fullinSudoku(board, rowUsed, colUsed, boxUsed, row, col + 1))
						{
							return true;
						}
						board[row][col] = '.';

						rowUsed[row][sequence] = false;
						colUsed[col][sequence] = false;
						boxUsed[row / 3][col / 3][sequence] = false;
					}



				}
			}
			else
			{
				return fullinSudoku(board, rowUsed, colUsed, boxUsed, row, col + 1);
			}

			return false;

		}
};
int main()
{
	Table Sudoku = { {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
					 {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
					 {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
					 {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
					 {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
					 {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
					 {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
					 {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
					 {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

	Solution().solveSudoku(Sudoku);
	for (int i = 0; i < Sudoku.size(); i++)
	{
		for (int j = 0; j < Sudoku[i].size(); j++)
		{
			cout << Sudoku[i][j] << ' ';
		}
		cout << endl;
	}
	
	return 0;
}