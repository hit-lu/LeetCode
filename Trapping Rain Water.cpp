// 2019/08/15
// Problem: Consider a bar like this:
//       
//           |
//       |   |      |
//       |   | |    |
//       | | | |    |
//       ------------
//    We can fill in this bars with water of 6 units
// Input  : { 3, 1, 4, 2, 0, 3 }
// Output :             6
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
	public:
		int trap(vector<int>& height) 
		{
			int left_max = 0, right_max = 0;
			int left = 1, right = height.size() - 2;
			int sum = 0;
			if (height.size() < 3)
			{
				return 0;
			}
			else
			{
				for (int i = 1; i < height.size() - 1; i++)
				{
					if (height[left - 1] < height[right + 1])
					{
						left_max = max(left_max, height[left - 1]);
						int min = left_max;
						if (min - height[left] > 0)
						{
							sum = sum + min - height[left];
						}
						left++;
					}
					else
					{
						right_max = max(right_max, height[right + 1]);
						int min = right_max;
						if (min - height[right] > 0)
						{
							sum = sum + min - height[right];
						}
						right--;
					}
				}
				return sum;
			}

		}
};

int main()
{
	vector<int> bars = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	cout << Solution().trap(bars);

	return 0;
}