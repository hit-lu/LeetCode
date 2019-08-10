// 2019/8/9
// Problem : Find a longest palindromic substring
// Example
// Input:  "aacdefcaa"
// Output: "aa" rather than "aac"
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	inline int Max(int a, int b)
	{
		return a > b ? a : b;
	}
	string longestPalindrome(string s)
	{
		int Str_Size = s.size();
		int Begin = 0, End = 0, Max_Size = 0;
		int Same_Count, Same_Mark = 0;
		string str_temp, str;
		for (int i = 1 - Str_Size; i <= Str_Size - 1; i++)        // size of malposition
		{
			Same_Count = 0;
			Same_Mark = 0;
			for (int j = 0; j < Str_Size; j++)
			{
				if (Str_Size - 1 - j + i >= 0 && i - j < 1 && s[j] == s[Str_Size - 1 - j + i])
				{
					if (Same_Mark == 0)
					{
						Same_Mark = 1;
						Begin = j;
					}
					End = j;
					Same_Count++;
				}
				else
				{
					if (Same_Mark == 0)
					{
						continue;
					}
					else
					{
						Same_Mark = 0;
						Same_Count = 0;
					}
				}
				if (Same_Count > Max_Size)
				{
					str_temp = s.substr(Begin, End - Begin + 1);
					// check the palindromic substring again
					for (int k = 0; k <= Same_Count / 2; k++)
					{
						if (str_temp[k] != str_temp[Same_Count - k - 1])
						{
							break;
						}
						else if (k == Same_Count / 2)
						{
							str = str_temp;
							Max_Size = Same_Count;
						}
					}
				}
			}
		}
		return str;

	}
};

int main()
{
	string s1 = "babad";
	string s2 = "aacdefcaa";
	cout << s2.substr(1, 2) << endl;
	cout << Solution().longestPalindrome(s1) << "     ";
	cout << Solution().longestPalindrome(s2) << endl;
	return 0;
}    