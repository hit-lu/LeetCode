#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
class Solution {
private:
	int DFSsearch(int row, int col , vector<vector<int>>& grid)
	{
		int ans = 1;
		if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()|| grid[row][col] == 0)
		{
			return 0;
		}
		// 上、下、左、右四个方向在水平和垂直方向的移动
		int HorStep[4] = { -1,1,0,0 }, VerStep[4] = { 0,0,-1,1 };

		grid[row][col] = 0;
		for (size_t i = 0; i < 4; i++)
		{
			ans += DFSsearch(row + HorStep[i], col + VerStep[i], grid);
		}
		return ans;
		

	}
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[0].size(); j++)
			{
				ans = max(ans, DFSsearch(i, j, grid));
			}
		}
		return ans;
	}
};



int main()
{
	vector<vector<int>> grid = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
							{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
							{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
							{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0 },
							{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
							{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 } };

	cout << Solution().maxAreaOfIsland(grid) << endl;
	return 0;
}