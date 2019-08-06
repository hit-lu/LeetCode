#include <iostream>
#include <vector>

using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {};       // initialize
};
class Solution
{
	public:
		ListNode* ConstuctList(vector<int> n)
		{
			ListNode* head = new ListNode(0), * cur = head;
			for (int i = 0; i < n.size(); i++)
			{
				cur->next = new ListNode(n[i]);
				cur = cur->next;
			}
			return head->next;

		}
		void PrintList(ListNode* head)
		{
			while (head->next != NULL)
			{
				cout << head->val << " -> ";
				head = head->next;
			}
			cout << head->val << endl;
		}
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode* head = new ListNode(0);
			ListNode* p = l1, *q = l2, *ret = head;

			int v1, v2, sum, carry = 0;
			while (p != NULL || q != NULL)
			{
				if (p != NULL) 	v1 = p->val, p = p->next;    else  v1 = 0;
				if (q != NULL)  v2 = q->val, q = q->next;    else  v2 = 0;
				sum = v1 + v2 + carry;
				carry = sum / 10;

				ret->next = new ListNode(sum % 10);
				ret = ret->next;
			}
			if (carry == 1)
			{
				ret->next = new ListNode(carry);
				ret = ret->next;
			}
			return head->next;
		}
};

int main()
{
	Solution S;
	ListNode* l1 = S.ConstuctList({ 0 });
	ListNode* l2 = S.ConstuctList({ });
	S.PrintList(S.addTwoNumbers(l1, l2));

	cout << "end" << endl;
	return 0;
}