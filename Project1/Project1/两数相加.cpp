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
/// ʵ���ϲ����ѣ���Ҫ��סC++ ����������ݽṹ�����о��Ǵ����������ͺ��ˣ�Ҳ��Ҫȥ���������ڸ��ӵ��㷨
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