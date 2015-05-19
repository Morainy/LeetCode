/*
 * =====================================================================================
 *
 *       Filename:  swapPairs.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月11日 21时33分38秒
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
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
	public:
		ListNode* swapPairs(ListNode* head);
		void swap(int * a , int *b)
		{
			int tmp = *a;
			*a = *b;
			*b = tmp;
		}
};

ListNode* Solution::swapPairs(ListNode* head)
{
	ListNode *p1 , *p2;
	if(!head || !(head->next)){
		return head;
	}
	p1 = head;
	p2 = head->next;
	while(p1 && p2){
		swap(&p1->val , &p2->val);
		if(p1->next){
			p1 = p1->next->next;
		}
		if(p2->next){
			p2 = p2->next->next;
		}
		else{
			break;
		}
	}
	return head;
}
int main(int argc , char * argv[])
{
	ListNode* head = NULL;
	Solution sol;
	head = sol.swapPairs(head);
	for(ListNode* p = head ; p ; p = p->next){
		cout<<p->val<<" ";
	}
	cout<<endl;
}
