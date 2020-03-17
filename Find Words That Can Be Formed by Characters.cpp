#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		unordered_map<char, int> charsCensus;
		int ans = 0;
		for (char c : chars)
		{
			charsCensus[c]++;
		}

		for (string w : words)
		{
			unordered_map<char, int> wordsCensus;
			bool IsAns = true;
			for (char c : w)
			{
				wordsCensus[c]++;
			}
			for (char c : w)
			{
				if (charsCensus[c] < wordsCensus[c])	// map 检索不存在的元素时值为 0
				{
					IsAns = false;
					break;
				}
			}
			if (IsAns)
			{
				ans += w.size();
			}
		}
		return ans;
	}
};

int main()
{
	vector<string> words = { "cat", "bt", "hat", "tree" };
	string chars = "atach";

	cout << Solution().countCharacters(words, chars) << endl;
	return 0;
}