// 2019/08/21 trackback problem
// Problem : get all the queen palce methods of a nxn chessboard
// Input : 4
// Output :  ".Q.."     "..Q."
//           "...Q"     "Q..."
//           "Q..."     "...Q"
//           "..Q."     ".Q.."

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution 
{
	private:
		// ---------------   private variables   ---------------   
		vector<bool> Principal_Diagonal;
		vector<bool> Counter_Diagonal;   // if the principal or counter diagonal is placed
		vector<bool> ColUsed;            // if the colum is placed

		vector<int> ColUsedIdx;		     // the colum that is placed Queens of each rows
		int Size;                        // the size of chessboard
		vector<vector<string>> ans;

		// ---------------   private functions   ---------------  
		bool checkUsable(int row, int col)
		{
			return !Principal_Diagonal[row - col + Size - 1] && !Counter_Diagonal[row + col] && !ColUsed[col];
		}
		void placeQueen(int row, int col)
		{
			Principal_Diagonal[row - col + Size - 1] = true;
			Counter_Diagonal[row + col] = true;
			ColUsed[col] = true;
			ColUsedIdx[row] = col;
			return;
		}
		void resetPos(int row, int col)
		{
			Principal_Diagonal[row - col + Size - 1] = false;
			Counter_Diagonal[row + col] = false;
			ColUsed[col] = false;
			return;
		}
		void recurisonPlace(int row)
		{
			if (row == Size)
			{
				vector<string> res;
				for (int i = 0; i < Size; i++)
				{
					string Lines(Size, '.');
					Lines[ColUsedIdx[i]] = 'Q';
					res.push_back(Lines);
				}
				ans.push_back(res);
			}
			else
			{
				for (int i = 0; i < Size; i++)
				{
					if (checkUsable(row, i))
					{
						placeQueen(row, i);
						recurisonPlace(row + 1);
						resetPos(row, i);
					}
				}
			}
			return;
		}
	public:
		// ---------------   public functions   --------------- 
		vector<vector<string>> solveNQueens(int n) 
		{
			
			Size = n;
			Principal_Diagonal = vector<bool>(2 * Size - 1, false);
			Counter_Diagonal = vector<bool>(2 * Size - 1, false);
			ColUsed = vector<bool>(Size, false);
			ColUsedIdx = vector<int>(Size, 0);

			recurisonPlace(0);

			return ans;
		}

};

int main()
{
	const int n = 4;
	vector<vector<string>> a = Solution().solveNQueens(n);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << endl;
		}
		cout << endl;
	}
	
	return 0;
}