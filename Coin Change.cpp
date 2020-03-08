// 20200308

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
private:
	vector<int> F;		// F(i) 表示凑成总金额 i 所需的最少的硬币个数
	int dp(vector<int>& coins, int res)
	{
		// 剩余金额分小于、等于、大于 0 三种情况进行讨论
		if (res < 0)
		{
			return -1;
		}	
		else if (res == 0)
		{
			return 0;
		}
		else
		{
			if (F[res - 1] != 0)
			{
				return F[res - 1];
			}

			int Min = INT_MAX;
			for (auto coin : coins)
			{
				int rem = dp(coins, res - coin);
				if (rem >= 0 && rem < Min)
				{
					Min = rem + 1;
				}
			}
			F[res - 1] = Min == INT_MAX ? -1 : Min;		// 保留计算过程中获得的量
			return F[res - 1];
		}

	}
public:
	int coinChange(vector<int>& coins, int amount) {
		F.resize(amount);
		if (amount <= 0)
		{
			return 0;
		}
		else
		{
			return dp(coins, amount);        // 动态规划
		}
	}
};

int main()
{
	vector<int> test{ 1,2,5 };
	cout << Solution().coinChange(test, 11) << endl;
	return 0;
}