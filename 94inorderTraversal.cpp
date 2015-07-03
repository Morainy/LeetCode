/*
 * =====================================================================================
 *
 *       Filename:  94inorderTraversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月02日 16时21分14秒
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
#include <stack>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		vector<int> inorderTraversal(TreeNode* root);
		vector<int> preorderTraversal(TreeNode* root);
		vector<int> postorderTraversal(TreeNode* root);
};

vector<int> Solution::inorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> s;
	while(root || !s.empty()){
		if(root){
			s.push(root);
			root = root->left;
		}else{
			root = s.top();
			s.pop();
			res.push_back(root->val);
			root = root->right;
		}
	}
	return res;
}

vector<int> Solution::preorderTraversal(TreeNode* root)
{
	vector<int> res;
	stack<TreeNode*> s;
	while(root || !s.empty()){
		if(root){
			res.push_back(root->val);
			s.push(root);
			root = root->left;
		}else{
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
	return res;
}

vector<int> Solution::postorderTraversal(TreeNode* root)
{
	vector<int> res;
	if(root == NULL){
		return res;
	}
	stack<TreeNode*> s;
	TreeNode* cur;
	TreeNode*pre = NULL;
	s.push(root);
	while(!s.empty()){
		cur = s.top();
		if((cur->left == NULL && cur->right == NULL) ||
					(pre != NULL  &&  (pre == cur->left || pre == cur->right))){
			res.push_back(cur->val);
			s.pop();
			pre = cur;
		}else{
			if(cur->right != NULL){
				s.push(cur->right);
			}
			if(cur->left != NULL){
				s.push(cur->left);
			}
		}
	}
}
int main(int argc , char* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);

	TreeNode* root = &node1;
	root->left = &node2;
	root->right = &node3;
	node3.left = &node4;
	node4.right = &node5;

	Solution sol;
	vector<int> res;

	res = sol.inorderTraversal(root);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	
	res = sol.preorderTraversal(root);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;

	res = sol.postorderTraversal(root);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
