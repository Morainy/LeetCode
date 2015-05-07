/*
 * =====================================================================================
 *
 *       Filename:  21mergeTwoLists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月07日 22时36分01秒
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
		ListNode* mergeTwoLists(ListNode* l1 , ListNode* l2);
};

ListNode* Solution::mergeTwoLists(ListNode* l1 , ListNode* l2)
{
	ListNode* front = new ListNode(0);
	ListNode *p1 = l1 , *p2 = l2;
	ListNode* p = front;
	while(p1 && p2){
		if(p1->val <= p2->val){
			p->next = p1;
			p1 = p1->next;
		}
		else{
			p->next = p2;
			p2 = p2->next;
		}
		p = p->next;
	}
	if(p1){
		p->next = p1;
	}
	if(p2){
		p->next = p2;
	}
	return front->next;
}

int main(int argc ,char * argv[])
{

}
