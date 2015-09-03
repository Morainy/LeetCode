/*
 * =====================================================================================
 *
 *       Filename:  138copyRandomList.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年09月02日 19时49分08秒
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

struct RandomListNode{
	int label;
	RandomListNode *next , *random;
	RandomListNode(int x):label(x) , next(NULL) , random(NULL){}
};

class Solution{
	public:
		RandomListNode *copyRandomList(RandomListNode* head);
};

RandomListNode* Solution::copyRandomList(RandomListNode* head)
{
	RandomListNode* ptr = head;
	if(!ptr){
		return NULL;
	}
	RandomListNode* tmp = NULL;
	while(ptr != NULL){
		tmp = new RandomListNode(ptr->label);
		tmp->next = ptr->next;
		ptr->next = tmp;
		ptr = tmp->next;
	}

	ptr = head;
	while(ptr != NULL){
		if(ptr->random){
			ptr->next->random = ptr->random->next;
		}
		ptr = ptr->next->next;
	}

	ptr = head;
	RandomListNode* res = ptr->next;
	RandomListNode* newTmp = res;
	while(ptr != NULL){
		tmp = ptr->next;
		ptr->next = tmp->next;
		ptr = ptr->next;
		if(newTmp != tmp){
			newTmp->next = tmp;
			newTmp = newTmp->next;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	RandomListNode node1(-1);
	//RandomListNode node2(11);
	//RandomListNode node3(12);
	//RandomListNode node4(13);

	//node1.next = &node2;
	//node2.next = &node3;
	//node3.next = &node4;


	Solution sol;
	RandomListNode* res = sol.copyRandomList(&node1);
	for(RandomListNode* ptr = res ; ptr ; ptr = ptr->next){
		cout<<ptr->label<<" ";
	}
	cout<<endl;
	return 0;
}