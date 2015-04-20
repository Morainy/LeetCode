/*
 * =====================================================================================
 *
 *       Filename:  110balancedBinaryTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 22时32分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
	public:
		bool isBalanced(TreeNode * root);
		int height(TreeNode * root);
		int max(int a , int b);
};

int Solution::max(int a , int b)
{
	return a > b?a:b;
}
int Solution::height(TreeNode * root)
{
	if(!root){
		return 0;
	}
	return max(height(root->left) ,  height(root->right)) + 1;
}
bool Solution::isBalanced(TreeNode *root)
{
	if(!root)
	  return true;
	if(!root->left && !root->right)
	  return true;
	int res =height(root->left) - height(root->right);
	if( res < -1 || res > 1){
		return false;
	}
	else{
		return isBalanced(root->left) && isBalanced(root->right);
	}
}

