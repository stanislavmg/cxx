#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode *t;

		if (!head || !head->next)
	 	 	return head;
		t = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return (t);
    }
};


int main(void){
	ListNode arr[10];
	ListNode *head = nullptr;
	Solution test;
	
	for (int i = 0; i < 9; ++i){
		arr[i].val = i;
		arr[i].next = &arr[i + 1];
	}
	arr[9].val = 9;
	arr[9].next = nullptr;
	for (ListNode *p = &arr[0]; p; p = p->next)
		cout << p->val << ' ';
	cout << endl;
	head = test.reverseList(arr);
	for (ListNode *p = head; p; p = p->next)
		cout << p->val << ' ';
	cout << endl;
	return 0;
}