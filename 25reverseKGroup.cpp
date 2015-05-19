/*
 * =====================================================================================
 *
 *       Filename:  25reverseKGroup.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月13日 09时53分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x) , next(NULL){}
};

class Solution{
	public:
		ListNode* reverseKGroup(ListNode* head , int k);
		ListNode* reverseList(ListNode* start , ListNode* end);
};

//翻转从start到end的链表节点，返回首节点指针
ListNode* Solution::reverseList(ListNode* start , ListNode* end)
{
	if(start == end){
		return start;
	}
	ListNode* p , *prev , *next;
	for(p = start , prev = NULL ; p != end ; prev = p , p = next){
		next = p->next;
		p->next = prev;
	}
	start->next = p->next;
	p->next = prev;
	return p;
}

ListNode* Solution::reverseKGroup(ListNode* head , int k)
{
	if(!head || k <= 1){
		return head;
	}
	ListNode* p = head;
	ListNode* prev = NULL;
	int count;
	bool flag = true;			//表示为第一次翻转k个元素
	
	vector<ListNode*> v;
	for(p = head , count = 0 ; p ; p = p->next , count++){
		if((count+1) % k == 0 || (count % k) == 0){
			v.push_back(p);
		}
	}
	for(int i = 0 ; i < v.size() -1 ; i = i + 2){
		if(flag){
			head = reverseList(v[i] , v[i+1]);
			//v[i]->next = NULL;
			prev = v[i];
			flag = false;
			continue;
		}
		prev->next = reverseList(v[i] , v[i+1]);
		prev = v[i];
	}
	return head;
}

int main(int argc , char * argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *newNode1 = new ListNode(2);
	ListNode *newNode2 = new ListNode(3);
	ListNode *newNode3 = new ListNode(4);
	ListNode *newNode4 = new ListNode(5);
	head->next = newNode1;
	newNode1->next = newNode2;
	newNode2->next = newNode3;
	newNode3->next = newNode4;

	Solution sol;
	head = sol.reverseKGroup(head , 2);
	ListNode* p;
	for(p = head ; p ; p = p->next){
		cout<<p->val<<" ";
	}
	cout<<endl;
}

