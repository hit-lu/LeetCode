// 2019/08/22
// Problem : get the length of the last word of a string
// Input :  "a  abc  "
// Output : 3
#include <iostream>
#include <string>
using namespace std;
class Solution 
{
	public:
		int lengthOfLastWord(string s)       
		{
			int Count = 0, Pre_Count = 0;
			bool space_flag = true;      
			for (int i = 0; i < s.size(); i++)
			{
				Count++;
				if (s[i] == ' ' && space_flag == false)
				{
					space_flag = true;
					Pre_Count = Count - 1;
					Count = 0;
				}
				else if (s[i] != ' ')
				{
					space_flag = false;
				}
				else
				{
					Count = 0;
				}
			}

			return (Count == 0) ? Pre_Count : Count;
		}
};

int main()
{
	cout << Solution().lengthOfLastWord("a  abc  ") << endl;
	return 0;
}