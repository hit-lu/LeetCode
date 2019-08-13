#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
	public:
		void placeBracket(vector<string>& bracket, string cur, int leftNum, int rightNum, int n)
		{
			if (cur.size() == 2 * n)
			{
				bracket.push_back(cur);
			}

			if (leftNum < n)
			{
				placeBracket(bracket, cur + '(', leftNum + 1, rightNum, n);
			}
			if (rightNum < leftNum)
			{
				placeBracket(bracket, cur + ')', leftNum, rightNum + 1, n);
			}

		}
		vector<string> generateParenthesis(int n) 
		{
			vector<string> validBracket;
			placeBracket(validBracket, "", 0, 0, n);
			return validBracket;
		}
};

int main()
{
	vector<string> ans = Solution().generateParenthesis(5);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}