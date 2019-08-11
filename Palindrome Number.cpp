// 2019/08/11 
// Problem : Check if the given number is palindrome
// Input : 123321     Output : true
// Input : 12         Output : false
// Input : 0          Output : true
#include <iostream>
using namespace std;

class Solution 
{
	public:
		bool isPalindrome(int x) 
		{
			int x_number = x, rev_number = 0;
			if (x_number < 0 || x_number % 10 == 0 && x_number != 0)
				return false;

			while (x_number > rev_number)
			{
				rev_number = rev_number * 10 + x_number % 10;
				x_number = x_number / 10;
			}

			if (x_number == rev_number || rev_number / 10 == x_number)
			{
				return true;
			}
            else
            {
                return false;
            }
		}
};

int main()
{
	cout << Solution().isPalindrome(12345) << endl;
	cout << Solution().isPalindrome(0) << endl;
	cout << Solution().isPalindrome(767) << endl;
	return 0;
}

