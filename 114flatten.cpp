/*
 * =====================================================================================
 *
 *       Filename:  114flatten.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月22日 16时41分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		void flatten(TreeNode* root);
};

void Solution::flatten(TreeNode* root)
{
	if(!root){
		return;
	}
	while(root){
		if(root->left){
			TreeNode* pre = root->left;
			while(pre->right){
				pre = pre->right;
			}
			pre->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		root = root->right;
	}
}
int main(int argc , char* argv[])
{

}
