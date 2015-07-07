/*
 * =====================================================================================
 *
 *       Filename:  98isValidBST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月07日 08时25分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		bool isValidBST(TreeNode* root);
};
class Solution{
public:
	bool isValidBST(TreeNode* root);
	void inorder(TreeNode* root , vector<int>& res);
};

bool Solution::isValidBST(TreeNode* root)
{
	vector<int> res;
	inorder(root , res);
	for(int i = 1 ; i < res.size() ; i++){
		if(res[i] <= res[i-1]){
			return false;
		}
	}
	return true;
}
void Solution::inorder(TreeNode* root , vector<int>& res)
{
	if(!root){
		return;
	}
	inorder(root->left , res);
	res.push_back(root->val);
	inorder(root->right , res);
}
