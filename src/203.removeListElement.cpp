#include <solution.h>

ListNode* Solution::removeElements(ListNode* head, int val){
	ListNode preHead{0};
	preHead.next = head;
	ListNode* pre = & preHead;

	while(head != nullptr){
		if(head->val == val){
			pre->next = head->next;
		}
		else{
			pre = head;
		}
		head = head->next;
	}
	
	return preHead.next;
}
