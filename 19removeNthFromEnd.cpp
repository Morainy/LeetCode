/*
 * =====================================================================================
 *
 *       Filename:  19removeNthFromEnd.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月07日 20时41分10秒
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
	ListNode * next;
	ListNode(int x):val(x) , next(NULL){}
};

class Solution{
	public:
		ListNode* removeNthFromEnd(ListNode* head , int n);
};

ListNode* Solution::removeNthFromEnd(ListNode* head , int n)
{
	if(!head){
		return head;
	}
	ListNode* front = new ListNode(0);
	front->next = head;
	ListNode * p1 = head , *p2 = head;
	ListNode * prev = front;
	int count = 0;
	while(p2){
		if(count >= n){
			prev = p1;
			p1 = p1->next;
		}
		p2 = p2->next;
		count++;
	}
	prev->next = p1->next;

	return front->next;
}

int main(int argc ,char * argv[])
{
	ListNode* head = new ListNode(1);
	Solution sol;
	head = sol.removeNthFromEnd(head , 1);

	for(ListNode* p = head ; p ; p=p->next){
		cout<<p->val<<"->";
	}
	cout<<endl;
	return 0;
}
