// 20200308  

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		
		int front = 0, last = nums.size() - 1;
		sort(nums.begin(), nums.end());
		int cloestThreeSum = nums[0] + nums[1] + nums[2], threeSum;
		

		for (size_t i = 0; i < nums.size() - 2; i++)
		{
			front = i + 1, last = nums.size() - 1;
			while (front < last)
			{
				threeSum = nums[i] + nums[front] + nums[last];
				if (abs(cloestThreeSum - target) > abs(threeSum - target))
				{
					cloestThreeSum = threeSum;
				}
				if (threeSum < target)
				{
					front++;
				}
				else if (threeSum > target)
				{
					last--;
				}
				else
				{
					return threeSum;
				}
			}
			while (i < nums.size() - 2 && nums[i] == nums[i + 1])
				i++;
		}
		return cloestThreeSum;
	}
};

int main()
{
	vector<int> test{ -1,2,1,-4 };
	cout << Solution().threeSumClosest(test, 1) << endl;
	return 0;
}