#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
	string compressString(string S) {
		string tmpS;
		int count = 1;
		for (size_t i = 1; i <= S.size(); i++)
		{
			if (i != S.size() && S[i] == S[i - 1])
			{
				count++;
			}
			else
			{
				// tmpS = tmpS + S[i - 1] + to_string(count);	// 超出内存限制
				tmpS += S[i - 1] + to_string(count);	// 通过
				count = 1;
			}
		}
		return tmpS.size() < S.size() ? tmpS : S;

	}
};

int main()
{
	string s = "aabccccca";
	cout << Solution().compressString(s) << endl;

	return 0;
}