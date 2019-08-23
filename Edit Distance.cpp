// 2019/08/23  dynamic programming
// Problem : computing editing distance like "honse" to "ros"
//			step 1. horse->rorse     replace 'h' with 'r'
//          step 2. rorse->rose      delete 'r'
//          step 3. rose->ros        delete 'e'
// Input : "honse"   "ros"
// Output :      3
#include <iostream>
#include <string>
//#include <Algorithm>

using namespace std;
class Solution 
{
	private:
		int min(int a, int b)
		{
			return a < b ? a : b;
		}
	public:
		int minDistance(string word1, string word2) 
		{
			const int len1 = word1.size(), len2 = word2.size();
			int ans = 1;
			int** dp = new int* [len1 + 1];    // including empty string
			if (len1 * len2 == 0)  return len1 + len2;

			// dp[i][j] is the step of coverting word1 to word2 
			// assuming after dp[i][j] step(s), word1[1...i] == word[1...j]
			for (int i = 0; i < len1 + 1; i++)
			{
				dp[i] = new int[len2 + 1];
				dp[i][0] = i;
			}

			for (int j = 0; j < len2 + 1; j++)
			{
				dp[0][j] = j;
			}

			for (int i = 1; i < len1 + 1; i++)
			{
				for (int j = 1; j < len2 + 1; j++)
				{
					if (word1[i - 1] == word2[j - 1])
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						// dp[i - 1][j]     ->  dp[i][j]    insert operation
						// dp[i - 1][j - 1] ->  dp[i][j]    replace operation
						// dp[i][j - 1]     ->  dp[i][j]    delete operation
						dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					}

				}
			}

			ans = dp[len1][len2];
			// free the  memory space of dynamic arrays
			for (int i = 0; i < len1 + 1; i++)
			{
				delete[] dp[i];
			}
			delete [] dp;

			return ans;
		}
};

int main()
{
	cout << Solution().minDistance("horse","ros") << endl;
	cout << Solution().minDistance("intention", "execution") << endl;
	cout << Solution().minDistance("apple", "area") << endl;
	return 0;
}