// 2019/08/14  greedy algorithm
// Problem : convert an integer to roman
// Input : 3         Output : III
// Input : 4         Output : IV
// Input : 10        Output : X

#include <iostream>
#include <map>
#include <string> 
using namespace std;

class Solution 
{
	public:
		string intToRoman(int num) 
		{
			map <int, string> idxRoman = { {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},
									{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"} };

			int number = num, map_key;
			string ans;
			while (number != 0)
			{
				// associated containers are not sequential in memory
				map<int, string>::iterator iter;
				for (iter = idxRoman.begin(); iter != idxRoman.end(); iter++)
				{
					if (number / iter->first == 0)// || (number / iter->first == 0 && number % iter->first == 0))
					{
						break;
					}
					map_key = iter->first;
				}
				ans = ans + idxRoman[map_key];
				number = number - map_key;
			}			
			return  ans;
		}
};
int main()
{
	cout << Solution().intToRoman(1) << endl;
	cout << Solution().intToRoman(4) << endl;
	cout << Solution().intToRoman(5) << endl;
	cout << Solution().intToRoman(9) << endl;
	cout << Solution().intToRoman(10) << endl;
	cout << Solution().intToRoman(40) << endl;
	cout << Solution().intToRoman(2731) << endl;
	return 0;
}