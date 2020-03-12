#include<iostream>
#include<string>

using namespace std;
class Solution {
private:
	int gcd(const int a, const int b)// 辗转相除法
	{
		return b == 0 ? a : gcd(b, a % b);
	}
public:
	string gcdOfStrings(string str1, string str2) {
		if (str1 + str2 == str2 + str1)
		{
			return str1.substr(0, gcd(str1.size(), str2.size()));
		}
		else
		{
			return "";
		}

	}
};

int main()
{
	string s1 = "ABABAB", s2 = "ABAB";
	cout << Solution().gcdOfStrings(s1, s2) << endl;
	return 0;
}