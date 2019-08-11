// 2019/08/12
// Problem: find three numbers whose sum is 0
// Input: {0,0,0}           Output: {0}
// Input: {2,0,-5,3,-4,4}   Output: {-4,0,4}  {2,-5,3}
// Input: {-5,2,4,1}        Output: None
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> res;
		if (nums.size() < 3)
		{
			return res;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			int first = i + 1, last = nums.size() - 1;
			do
			{
				int result = nums[i] + nums[first] + nums[last];
				if (result == 0)
				{
					res.push_back({ nums[i],nums[first],nums[last] });
				}
				if (result <= 0 && first < last)
				{
					while (first < last)
					{
						first++;
						if (nums[first] != nums[first - 1])
						{
							break;
						}
					}
				}
				else if(first < last)
				{
					while (first < last)
					{
						last--;
						if (nums[last] != nums[last + 1])
						{
							break;
						}
					}
				}
			} while (first < last );
			while (nums[i] == nums[i + 1] && i < nums.size() - 2) i++;
		}
		return res;
	}
};
int main()
{
	vector<vector<int>> output;
	vector<int> input = {2,-5,3,4,-4,0};
	output = Solution().threeSum(input);
	for (int i = 0; i < output.size(); i++)
	{
		for (int j = 0; j < output[i].size(); j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}