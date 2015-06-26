/*
 * =====================================================================================
 *
 *       Filename:  86partitionList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月24日 16时33分20秒
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
		ListNode* partition(ListNode* head , int x);
};

ListNode* Solution::partition(ListNode* head , int x)
{
	/*ListNode front(x-1);
	front.next = head;
	ListNode* smaller = &front , *prev = &front;
	ListNode* cur = head;
	while(cur){
		if(cur->val < x){
			ListNode* tmp = cur->next;
			if(cur != smaller->next){
				cur->next = smaller->next;
			}
			smaller->next = cur;
			smaller = cur;
			prev->next = tmp;
			cur = tmp;
		}else{
			prev = cur;
			cur = cur->next;
		}
	}
	return front.next;*/

	ListNode* cur = head;
	ListNode d1(0);
	ListNode d2(0);
	ListNode* e1 = &d1;
	ListNode* e2 = &d2;
	while(cur){
		if(cur->val < x){
			e1->next = cur;
			e1 = e1->next;
		}else{
			e2->next = cur;
			e2 = e2->next;
		}
		cur = cur->next;
	}
	e2->next = NULL;
	e1->next = d2.next;
	return d1.next;
}

int main(int argc , char* argv[])
{
	ListNode node1(1);
	ListNode node2(1);
	/*ListNode node2(4);
	ListNode node3(3);
	ListNode node4(2);
	ListNode node5(5);
	ListNode node6(2);*/

	ListNode* head = &node1;
	node1.next = &node2;
	/*node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;*/

	Solution sol;
	int x = 3;
	head = sol.partition(head , x);

	ListNode* p = head;
	while(p){
		cout<<p->val<<"->";
		p = p->next;
	}
	cout<<endl;
}

