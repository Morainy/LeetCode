/*
 * =====================================================================================
 *
 *       Filename:  82deleteDuplicates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月20日 11时13分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x) , next(NULL){}
};

class Solution{
	public:
		ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head)
{
	if(!head){
		return head;
	}
	ListNode* fakeHead = new ListNode(head->val -1);
	ListNode* prev = fakeHead;
	fakeHead->next = head;
	ListNode* cur = head;

	while(cur){
		if(cur->next && cur->val == cur->next->val){
			int val = cur->val;
			while(cur && cur->val == val){
				ListNode* t = cur->next;
				prev->next = t;
				//delete cur;
				cur = t;
			}
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	return fakeHead->next;
}

int main(int argc , char* argv[])
{
	ListNode* head;
	ListNode node1(1);
	ListNode node2(1);
	ListNode node3(2);
	//ListNode node4(2);
	//ListNode node5(3);
	//ListNode node6(4);
	//ListNode node7(5);

	head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	//node3.next = &node4;
	//node4.next = &node5;
	//node5.next = &node6;
	//node6.next = &node7;

	Solution sol;
	ListNode* p = sol.deleteDuplicates(head);
	while(p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<endl;
}

