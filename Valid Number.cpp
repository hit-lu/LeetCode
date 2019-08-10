// 2019/08/11  Table-Driven Methods
// Problem : check the validity of a string which describes a decimal number
// Input - "1e3"         Output - true
// Input - "3."          Output - true
// Input - " ."          Output - false
// Input - "+4"          Output - true
// Input - "2e-4.2"      Output - false
#include <iostream>
#include <string>
using namespace std;
class Solution
{
private:                                                // transfer matrix
	// respectively represent: blank, +/-, 0~9, dot, e/E，others
	char transfer[9][6] = { { 0,  1, 6,  2, -1, -1},           // state 0
							{-1, -1, 6,  2, -1, -1},			// state 1
							{-1, -1, 3, -1, -1, -1},			// state 2
							{ 8, -1, 3, -1,  4, -1},			// state 3
							{-1,  7, 5, -1, -1, -1},			// state 4
							{ 8, -1, 5, -1, -1, -1},			// state 5
							{ 8, -1, 6,  3,  4, -1},			// state 6
							{-1, -1, 5, -1, -1, -1},			// state 7
							{ 8, -1,-1, -1, -1, -1} }; 			// state 8
	bool finals[9] = { 0, 0, 0, 1, 0, 1, 1, 0, 1 };
	int GetCharType(char ch)
	{
		switch (ch)
		{
		case ' ':	return 0;
		case '+':
		case '-':	return 1;
		case '.':	return 3;
		case 'e':
		case 'E':	return 4;
		default:
			if (ch >= 48 && ch <= 57)
			{
				return 2;
			}
			else
			{
				return 5;
			}
		}
	}
public:
	bool isNumber(string s)
	{
		int state = 0, i = 0;
		for (; i < s.size(); i++)
		{
			state = transfer[state][GetCharType(s[i])];
			if (state == -1)
			{
				return false;
			}
		}
		return finals[state];

	}
};

int main()
{
	cout << Solution().isNumber("1e3") << endl;
	cout << Solution().isNumber("3.") << endl;
	cout << Solution().isNumber(" .") << endl;
	cout << Solution().isNumber("+4") << endl;
	cout << Solution().isNumber("2e-4.2") << endl;
	return 0;
}