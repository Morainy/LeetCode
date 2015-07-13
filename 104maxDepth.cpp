/*
 * =====================================================================================
 *
 *       Filename:  104maxDepth.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月13日 10时15分42秒
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
		int maxDepth(TreeNode* root);
		void solve(TreeNode* root , int& res);
};

void Solution::solve(TreeNode* root , int& res)
{
	if(!root){
		return;
	}
	if(!(root->left) && !(root->right)){
		res += 1;
		return;
	}
	res += 1;
	int depthLeft = 0 , depthRight = 0;
	solve(root->left , depthLeft);
	solve(root->right , depthRight);
	if(depthLeft <= depthRight){
		res += depthRight;
	}else{
		res += depthLeft;
	}
}

int Solution::maxDepth(TreeNode* root)
{
	int res = 0;
	solve(root , res);
	return res;
}

int main(int argc , char* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	
	TreeNode* root = &node1;
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node3.right = &node5;
	node5.right = &node6;

	Solution sol;
	int res = 0;
	res = sol.maxDepth(root);
	cout<<"res = "<<res<<endl;
}
