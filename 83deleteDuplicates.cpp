/*
 * =====================================================================================
 *
 *       Filename:  83deleteDuplicates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月20日 10时37分14秒
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
	ListNode *next;
	ListNode(int x):val(x) , next(NULL){}
};

class Solution{
	public:
		ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head)
{
	if(!head || !head->next){
		return head;
	}
	ListNode* start = head;
	ListNode* p = head;
	while(p->next){
		if(p->next->val != start->val){
			if(start != p || start->next != p){
				start->next = p->next;
				start = p->next;
			}
		}
		p = p->next;
	}
	if(p->val == start->val){
		start->next = NULL;
	}
	return head;
}
int main(int argc , char* argv[])
{
	ListNode* head;
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	//ListNode node4(3);
	//ListNode node5(3);

	head = &node1;
	node1.next = &node2;
	node2.next = &node3;
	//node3.next = &node4;
	//node4.next = &node5;

	Solution sol;
	ListNode* p = sol.deleteDuplicates(head);

	while(p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<endl;
}

