#include <solution.h>

ListNode* Solution::reverseList(ListNode* head){
	if(head == nullptr){
		return head;
	}
	ListNode* res = head;
	ListNode* current = head->next;
	while(current != nullptr){
		head->next = current->next;
		current->next = res;
		res = current;
		current = head->next;
	}
	return res;
}
