/*
 * =====================================================================================
 *
 *       Filename:  99recoverTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月07日 08时28分26秒
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

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		void recoverTree(TreeNode* root);
		void inorder(vector<TreeNode*>& v , TreeNode* root);
		void swap(TreeNode* node1 , TreeNode* node2);
};

void Solution::swap(TreeNode* node1 , TreeNode* node2)
{
	int tmp = node1->val;
	node1->val = node2->val;
	node2->val = tmp;
}

void Solution::inorder(vector<TreeNode*>& v , TreeNode* root)
{
	if(!root){
		return;
	}
	inorder(v , root->left);
	v.push_back(root);
	inorder(v , root->right);
}

void Solution::recoverTree(TreeNode* root)
{
	if(!root){
		return;
	}
	vector<TreeNode*> vTree;
	inorder(vTree , root);
	int first = -1 , second = -1;
	for(int i = 0 ; i <vTree.size()-1 ; i++){
		if(vTree[i]->val > vTree[i+1]->val){
			if(first < 0){
				first = i;
			}else{
				second = i;
			}
		}
	}
	if(second < 0){
		swap(vTree[first] , vTree[first+1]);
	}else{
		swap(vTree[first] , vTree[second+1]);
	}
}

int main(int argc , char* argv[])
{

}

