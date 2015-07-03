/*
 * =====================================================================================
 *
 *       Filename:  reverseBetween.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月02日 09时37分36秒
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
		ListNode* reverseBetween(ListNode* head , int m , int n);
};

ListNode* Solution::reverseBetween(ListNode* head , int m , int n)
{
	if(!head || !head->next){
		return head;
	}
	int cnt = 1;
	ListNode* cur = head;
	ListNode* prev = NULL;
	ListNode* start = NULL , *end = NULL;
	while(cur){
		if(cnt == m -1){
			start = cur;
		}
		if(cnt == n + 1){
			end = cur;
			break;
		}
		cnt++;
		cur = cur->next;
	}
	cur = head;
	cnt = 1;
	while(cur){
		if(cnt == m){
			ListNode* next = cur->next;
			cur->next = end;
			prev = cur;
			cur = next;
			cnt++;
			continue;
		}
		if(cnt == n){
			ListNode* next = cur->next;
			cur->next = prev;
			if(start){
				start->next = cur;
			}else{
				head = cur;
			}
			cur = next;
			cnt++;
			continue;
		}
		if(cnt > m && cnt < n){
			ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			cnt++;
			continue;
		}
		cnt++;
		prev = cur;
		cur = cur->next;
	}
	return head;
}

int main(int argc , char* argv[])
{
	ListNode Node1(3);
	ListNode Node2(5);
	//ListNode Node3(3);
	//ListNode Node4(4);
	//ListNode Node5(5);

	ListNode* head = &Node1;
	Node1.next = &Node2;
	/*Node2.next = &Node3;
	Node3.next = &Node4;
	Node4.next = &Node5;*/
	Solution sol;
	head = sol.reverseBetween(head , 1 , 2);

	ListNode* ptr = head;
	while(ptr){
		cout<<ptr->val<<"->";
		ptr = ptr->next;
	}
	cout<<endl;
}

