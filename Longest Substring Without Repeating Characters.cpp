// Find the longest substr without repeating characters
// Example:
// Input - "hello"     Output - 3
// Input - "abba"      Output - 2
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution 
{
	public:
		int lengthOfLongestSubstring(string s) 
		{
			map<char, size_t> ch;
			int Max_Size = 0;
			for (int start = 0, end = 0; end < s.size(); end++)
			{
				char Alpha = s[end];
				if (ch.find(Alpha) != ch.end())          // find the character in the map
				{
					// the position of Alpha is ch[Alpha]
					start = ch[Alpha] + 1 > start ? ch[Alpha] + 1 : start;
				}
				ch[Alpha] = end;
				Max_Size = Max_Size > end - start + 1 ? Max_Size : end - start + 1;
			}
			return Max_Size;
		}
};

int main()
{
	string str = "abba";
	cout << "The longest substring of " << str << " without repeating characters has" <<  endl;
	cout << Solution().lengthOfLongestSubstring(str) << " characters" << endl;
	return 0;
}