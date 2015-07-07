/*
 * =====================================================================================
 *
 *       Filename:  101isSymmetric.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月07日 09时07分13秒
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
		bool isSymmetric(TreeNode* root);
		bool check(TreeNode* root1 , TreeNode* root2);
};

bool Solution::check(TreeNode* root1 , TreeNode* root2)
{
	if(!root1 && !root2){
		return true;
	}
	if(!root1 || !root2 || root1->val != root2->val){
		return false;
	}
	return check(root1->left , root2->right) && check(root1->right , root2->left);
}

bool Solution::isSymmetric(TreeNode* root)
{
	if(!root){
		return true;
	}
	return check(root->left , root->right);
}

int main(int argc , char* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);

	TreeNode* root = &node1;
	node1.left = &node2;
	node1.right = &node3;

	Solution sol;
	cout<<sol.isSymmetric(root)<<endl;
}

