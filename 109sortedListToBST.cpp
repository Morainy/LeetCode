/*
 * =====================================================================================
 *
 *       Filename:  109sortedListToBST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 10时30分07秒
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
	ListNode(int x):val(x), next(NULL){}
};

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL) , right(NULL){}
};

class Solution{
	public:
		TreeNode* sortedListToBST(ListNode* head);
};

TreeNode* Solution::sortedListToBST(ListNode* head)
{
	if(!head){
		return NULL;
	}
	ListNode* iRoot = head;
	ListNode* prev = head;
	ListNode* fast = head;
	while(fast){
		if(fast->next){
			fast = fast->next->next;
		}else{
			break;
		}
		prev = iRoot;
		iRoot = iRoot->next;
	}
	prev->next = NULL;
	TreeNode* root = new TreeNode(iRoot->val);
	root->right = sortedListToBST(iRoot->next);
	if(iRoot == head){
		root->left = sortedListToBST(NULL);
	}else{
		root->left = sortedListToBST(head);
	}
	return root;
}

int main(int argc , char* argv[])
{

}
