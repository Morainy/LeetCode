/*
 * =====================================================================================
 *
 *       Filename:  23mergeKLists.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月09日 22时12分35秒
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
#include <algorithm>
#include <queue>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x) , next(NULL){}
};

class Solution{
	public:
		ListNode* mergeKLists(vector<ListNode*> & lists);
		struct cmp{
			bool operator()(const ListNode* a , const ListNode* b){
				return a->val > b->val;
			}
		};
};


ListNode* Solution::mergeKLists(vector<ListNode*>& lists)		//应用小顶堆取最小元素
{
	ListNode* front = new ListNode(0);
	ListNode* p = front;
	
	vector<int> heap;
	for(int i = 0 ; i < lists.size() ; i++){
		if(lists[i]){
			heap.push_back(lists[i]->val);
		}
	}
	priority_queue<ListNode* , vector<ListNode*> , cmp> que;	
	for(int i = 0 ; i < lists.size() ; i++){
		if(lists[i]){
			que.push(lists[i]);
		}
	}
	while(!que.empty()){
		ListNode* tmp = que.top();
		que.pop();
		p->next = tmp;
		p = p->next;
		
		if(tmp->next){
			que.push(tmp->next);
		}
	}
	return front->next;
}

/*ListNode* Solution::mergeKLists(vector<ListNode*>& lists)
{
	ListNode* front = new ListNode(0);
	ListNode* p = front;
	int min = 0;
	if(lists.size() <= 0){
		return NULL;
	}
	int i;
	int count;											//统计lists数组中空指针的数量
	bool flag = true;									//表示lists数组中仍有不为空的元素
	while(flag){
		count = 0;
		min = -1;
		for(i = 0 ; i < lists.size() ; i++){
			if(!lists[i]){
				count++;
				continue;
			}
			if(min == -1){
				min = i;
			}
			if(lists[i] && lists[min] && lists[min]->val > lists[i]->val){
				min = i;
			}
		}
		if(min >= 0){
			p->next = lists[min];
		}
		p = p->next;
		if(min >= 0 && lists[min]){
			lists[min] = lists[min]->next;
		}
		if(count == lists.size()){
			flag = false;
		}
	}
	return front->next;
}*/

int main(int argc , char * argv[])
{
	Solution sol;
	ListNode* newNode1 = new ListNode(1);
	ListNode* newNode2 = new ListNode(0);
	vector<ListNode*> lists;
	lists.push_back(newNode1);
	lists.push_back(newNode2);
	ListNode* head = sol.mergeKLists(lists);
	ListNode* p;
	for(p = head ; p ; p = p->next){
		cout<<p->val<<"->";
	}
	cout<<endl;
}

