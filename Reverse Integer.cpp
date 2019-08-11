// 2019/8/10 
// Problem : Reverse a number in the integer range
// Example
// Input:  123             Output: 321
// Input:  2147483648      Output: 0
#include <iostream>
#include <climits>

using namespace std;
class Solution 
{
	public:
		int reverse(int x) 
		{
			int last_number, rev_number = 0;
			while (x != 0)
			{
				last_number = x % 10;
				x = x / 10;

				if (rev_number == INT_MAX / 10 && last_number > 7 || rev_number > INT_MAX / 10)
				{
					rev_number = 0;
					break;
				}
				else if(rev_number  == INT_MIN / 10 & last_number < -8 || rev_number < INT_MIN / 10)
				{
					rev_number = 0;
					break;
				}
				rev_number = rev_number * 10 + last_number;
			}
			return rev_number;
		}
};
int main()
{
	cout << Solution().reverse(12345) << endl;
	return 0;
}