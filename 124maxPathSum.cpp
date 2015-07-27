/*
 * =====================================================================================
 *
 *       Filename:  124maxPathSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月27日 10时21分27秒
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
#include <limits>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		int max = numeric_limits<int>::min();
		int maxPathSum(TreeNode* root);
		int solve(TreeNode* root);
};

int Solution::solve(TreeNode* root)
{
	if(!root){
		return 0;
	}
	int value = root->val;
	int lmax = 0;
	int rmax = 0;
	if(root->left){
		lmax = solve(root->left);
		if(lmax > 0){
			value += lmax;
		}
	}
	if(root->right){
		rmax = solve(root->right);
		if(rmax > 0){
			value += rmax;
		}
	}

	if(value > max){
		max = value;
	}
	if(lmax > rmax){
		return root->val>root->val+lmax?root->val:root->val+lmax;
	}else{
		return root->val > root->val + rmax?root->val:root->val+rmax;
	}
}

int Solution::maxPathSum(TreeNode* root)
{
	if(!root){
		return 0;
	}
	solve(root);
	return max;
}

int main(int argc , char* argv[])
{

}
