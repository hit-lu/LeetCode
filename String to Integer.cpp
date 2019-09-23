// 2019/09/23
// Problem: Convert a string into integer

#include <string>
#include <iostream>
using namespace std;

#define INT_MAX 2147483647             // 32 位整型能够存储的最大的数
class Solution
{
public:
	int myAtoi(string str)         // 字符串转换为整数，注意：只能使用 32 位存储变量
	{
		int ans = 0;               // 转换后的结果
		int len = 0;               // 记录读入有效信息的长度，为了规避测试数据“+-2”
		bool Positive_Num = true;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' '&& len == 0)
			{
				continue;
			}
			else if ((str[i] == '+' || str[i] == '-') && len == 0)
			{
				len++;
				if (str[i] == '-')
					Positive_Num = false;       // 所求数为负数
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				len++;
				if ((INT_MAX - (str[i] - '0')) / 10 < ans)
				{
					return Positive_Num ? INT_MAX : -INT_MAX - 1;
					break;
				}
				ans = ans * 10 + (str[i] - '0');
			}
			else
			{
				break;
			}
		}
		return (Positive_Num == true) ? ans : -ans;
	}
};

int main()
{
	cout << Solution().myAtoi("42") << endl;                   // 42
	cout << Solution().myAtoi("   -42") << endl;               // -42
	cout << Solution().myAtoi("4193 with words") << endl;      // 4193
	cout << Solution().myAtoi("words and 987") << endl;        // 987
	cout << Solution().myAtoi("-91283472332") << endl;         // -2147483648
	cout << Solution().myAtoi("2147483646") << endl;           // 2147483646
	cout << Solution().myAtoi("-+1") << endl;                  // 0
	cout << Solution().myAtoi("   +0 123") << endl;            // 0
	return 0;
}