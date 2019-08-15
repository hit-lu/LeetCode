#include <iostream>
#include <string>
using namespace std;
class Solution 
{
	public:
		string multiply(string num1, string num2) 
		{
			string ans(num1.size() + num2.size(), '0');

			for (int i = num1.size() - 1; i >= 0; i--)
			{
				for (int j = num2.size() - 1; j >= 0; j--)
				{
					int sum = (num1[i] - '0') * (num2[j] - '0') + ans[i + j + 1] - '0';
					ans[i + j + 1] = sum % 10 + '0';
					ans[i + j] = ans[i + j] + sum / 10;
				}
			}

			for (int i = 0; i < ans.size(); i++)
			{
				if (ans[i] != '0' || i == ans.size() - 1)
				{
					ans = ans.substr(i, ans.size() - i);
					break;
				}
			}

			return ans;
		}
};

int main()
{
	cout << Solution().multiply("123", "456") << endl;

	return 0;
}