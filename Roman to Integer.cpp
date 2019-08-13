#include<iostream>
#include<map>

using namespace std;

class Solution 
{
	public:
		int romanToInt(string s) 
		{
			map<string, int> Roman = { {"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},
								   	  {"IV",3},{"IX",8},{"XL",30},{"XC",80},{"CD",300},{"CM",800} };
			
			string oneElement, twoElement;
			int value = Roman[s.substr(0, 1)];
			for (int i = 1; i < s.size(); i++)
			{
				oneElement = s.substr(i, 1);
				twoElement = s.substr(i - 1, 2);
				value = value + (Roman[twoElement] ? Roman[twoElement] : Roman[oneElement]);
			}
			return value;
		}
};
int main()
{
	cout << Solution().romanToInt("IV");
	return 0;
}