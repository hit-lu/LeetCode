// 2019/08/19
// Problem : find whether the word is in the board orderly or not
// Input : 
//		board =
//		[
//		  ['A','B','C','E'],
//		  ['S','F','C','S'],
//		  ['A','D','E','E']
//		]

//	 word = "ABCCED"     true.
//	 word = "SEE"        true.
//	 word = "ABCB"       false.


#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution 
{
	private:
		struct offset
		{
			short int vert;
			short int Horiz;
		};
		struct offset Move[4];
	public:
		Solution()
		{
			Move[0] = {  0, 1 };    // 上
			Move[1] = {  0,-1 };    // 下
			Move[2] = { -1, 0 };    // 左
			Move[3] = {  1, 0 };    // 右
		}
		bool recursive(vector<vector<char>>& board, vector<vector<bool>> Mark, int row, int col, string word)
		{
			int cur_row, cur_col;
			int real_row = row, real_col = col;
			int row_size = board.size(), col_size = board[0].size();

			if (word.size() == 0)
			{
				return true;
			}
			else
			{
				for (int dir = 0; dir < 4; dir++)
				{
					cur_row = row + Move[dir].Horiz;
					cur_col = col + Move[dir].vert;
					if (cur_row < row_size && cur_row >= 0 && cur_col < col_size && cur_col >= 0  )
					{
						if (Mark[cur_row][cur_col] == false && board[cur_row][cur_col] == word[0])
						{
							Mark[cur_row][cur_col] = true;
							if (recursive(board, Mark, cur_row, cur_col, word.substr(1, word.size() - 1)))
							{
								return true;
							}
							else
							{
								Mark[cur_row][cur_col] = false;
							}
						}
					}
				}
				return false;
			}

		}
		bool exist(vector<vector<char>>& board, const string word) 
		{
			vector<vector<bool>> Mark(board.size(), vector<bool>(board[0].size(), false));
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
				{
					if (board[i][j] == word[0])
					{
						Mark[i][j] = true;
						if (recursive(board, Mark, i, j, word.substr(1, word.size() - 1)))
						{
							return true;
						}
						else
						{
							Mark[i][j] = false;
						}
					}
				}
			}
			return false;

		}
};

int main()
{
	vector<vector<char>> board = { {'A','B','C','E'}, {'S','F','C','S'},{'A','D','E','E' } };
	cout << Solution().exist(board, "SEE") << endl;
	cout << Solution().exist(board, "ABCCED") << endl;
	cout << Solution().exist(board, "ABCB") << endl;

	return 0;
}