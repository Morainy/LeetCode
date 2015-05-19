/*
 * =====================================================================================
 *
 *       Filename:  2addTwoNumbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月21日 15时10分11秒
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
		ListNode* addTwoNumbers(ListNode* l1 , ListNode* l2);
};

ListNode * Solution::addTwoNumbers(ListNode* l1 , ListNode* l2)
{
	ListNode * resHead = NULL;
	int increment = 0;
	int sum , newval;
	int l1val , l2val;
	ListNode *ptr = resHead;
	if(!l1){
		return l2;
	}
	if(!l2){
		return l1;
	}
	while(l1 || l2){
		
		if(l1)
		  l1val = l1->val;
		else
		  l1val = 0;
		if(l2)
		  l2val = l2->val;
		else
		  l2val = 0;

		sum = l1val + l2val + increment;
		increment = sum / 10;
		newval = sum % 10;

		ListNode * newNode = new ListNode(newval);
		if(!ptr){
			ptr = newNode;
			resHead = ptr;
		}
		else{
			ptr->next = newNode;
			ptr = ptr->next;
		}
		if(l1){
			l1 = l1->next;
		}
		if(l2){
			l2 = l2->next;
		}
	}
	if(increment){
		ListNode *newNode = new ListNode(increment);
		ptr->next = newNode;
		ptr = ptr->next;
	}
	return resHead;
}

int main()
{
	ListNode * l1= NULL , *l2 = NULL;
	ListNode * newNode = new ListNode(5);
	l1 = newNode;
	newNode = new ListNode(5);
	l2 = newNode;

	ListNode *res;
	Solution sol;
	res = sol.addTwoNumbers(l1 , l2);
	while(res){
		cout<<res->val<<" ";
		res = res->next;
	}
	cout<<endl;
}
