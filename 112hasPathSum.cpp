/*
 * =====================================================================================
 *
 *       Filename:  112hasPathSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 14时15分45秒
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
		bool hasPathSum(TreeNode* root , int sum);
};

bool Solution::hasPathSum(TreeNode* root , int sum)
{
	if(!root){
		return false;
	}
	if(!(root->left) && !(root->right) && root->val == sum){
		return true;
	}
	int value = root->val;
	if(hasPathSum(root->left , sum - value)){
		return true;
	}else{
		return hasPathSum(root->right , sum - value);
	}
}

int main(int argc , char* argv[])
{

}
