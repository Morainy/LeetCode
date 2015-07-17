/*
 * =====================================================================================
 *
 *       Filename:  111minDepth.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 13时51分17秒
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
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};
class Solution{
	public:
		int minDepth(TreeNode* root);
		int solve(vector<TreeNode*>& nodes , TreeNode* root);
};

int Solution::solve(vector<TreeNode*>& nodes , TreeNode* root)
{
	if(nodes.size() < 1){
		return 0;
	}
	vector<TreeNode*> tmp;
	for(int i = 0 ; i < nodes.size() ; i++){
		if(nodes[i]->left){
			tmp.push_back(nodes[i]->left);
		}
		if(nodes[i]->right){
			tmp.push_back(nodes[i]->right);
		}
		if(!(nodes[i]->left) && !(nodes[i]->right)){
			return 1;
		}
	}
	return solve(tmp , root)+1;
}

int Solution::minDepth(TreeNode* root)
{
	if(!root){
		return 0;
	}
	vector<TreeNode*> tmp;
	tmp.push_back(root);
	return solve(tmp , root);
}

int main(int argc , char* argv[])
{

}
