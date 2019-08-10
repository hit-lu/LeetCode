// 2019/7/29 Stack
// Problem : check the validity of a string which describes brackets
// Example
// Input:  string - "[{(){}}]" 
// Output: true
//
// Input:  string - "[(}}]" 
// Output: false
//
// Input:  string - "" 
// Output: true
#include <iostream>
#include <string>
using namespace std;

#define ElementType char
#define ERROR -1

typedef struct SNode* PtrToSNode;
struct SNode
{
	ElementType Data;
	PtrToSNode Next;
};
class Solution {
    private:
		PtrToSNode S;
	public:
		Solution()
		{
			S = new struct SNode;                // 类型定义和变量定义应区别对待
			S->Next = NULL;
			
		}
		bool Push(ElementType X)
		{
			PtrToSNode TmpCell = new struct SNode;

			TmpCell->Data = X;
			TmpCell->Next = S->Next;
			S->Next = TmpCell;     // 此处建议画图再好好了解下

			return true;
		}

		ElementType Pop()
		{
			PtrToSNode FirstCell;
			ElementType temp;

			if(S->Next == NULL)
			{
				return ERROR;
			}
			else
			{
				FirstCell = S->Next;
				temp = FirstCell->Data;
				S->Next = FirstCell->Next;

				delete FirstCell;

				return temp;
			}
		}

		ElementType Bracket_Map(ElementType ch)
		{
			ElementType temp;
			switch(ch)
			{
				case '(':   temp = ')';  break;
				case '[':   temp = ']';  break;
				case '{':   temp = '}';  break;
				default:    temp = ERROR;
			}
			return temp;
		}

		bool isValid(string s) 
		{
			ElementType right;
			bool result = false;
			if(s.size() == 0)
				return true;
			for(int i = 0; i < s.size(); i ++)
			{
				if(s[i] == '{' || s[i] == '(' || s[i] == '[')
					Push(s[i]);
				else if(s[i] == '}' || s[i] == ')' || s[i] == ']')
				{
					right = Bracket_Map(Pop());
					if(s[i] != right || right == -1)
					{
						// cout << "false" << endl;
						result = false;
						break;
					}
				}
				else
				{
					// cout << "false" << endl;
					result = false;
				}
				if(i == s.size() - 1 && S->Next == NULL) result = true;
			}
			return result;
		}
};

int main()
{
	string param_1 = "[";
	bool ret = Solution().isValid(param_1);

	cout << ret << endl;

	return 0;
}