#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main()
{
	
}


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/// <summary>
/// 实际上并不难，需要记住C++ 中链表的数据结构，还有就是处理各种情况就好了，也不要去搞其他过于复杂的算法
/// </summary>
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		int nextValue = 0;
		while (l1 != nullptr || l2 != nullptr)
		{
			int a = 0;
			int b = 0;

			if (l1 != nullptr)
			{
				a = l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				b = l2->val;
				l2 = l2->next;
			}

			int sum = a + b + nextValue;
			cur->val = sum % 10;

			if (sum >= 10)
			{
				nextValue = 1;
			}
			else
			{
				nextValue = 0;
			}

			if ((l1 != nullptr || l2 != nullptr) && nextValue == 0)
			{
				cur->next = new ListNode(-1);
				cur = cur->next;
			}
			else if (nextValue == 1)
			{
				cur->next = new ListNode(1);
				cur = cur->next;
			}
		}
		return head;
	}
};