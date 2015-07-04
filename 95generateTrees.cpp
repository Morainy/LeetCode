/*
 * =====================================================================================
 *
 *       Filename:  95generateTrees.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月03日 09时59分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
using namespace	std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		vector<TreeNode*> generateTrees(int n);
		//void solve(vector<TreeNode*>& res , TreeNode* root ,TreeNode* cur , int n);
		vector<TreeNode*> createTree(int start , int end);
};

vector<TreeNode*> Solution::generateTrees(int n)
{
	/*vector<TreeNode*> res;
	if(n == 0){
		return res;
	}
	TreeNode node(n);
	TreeNode* root = &node;
	TreeNode* cur = root;
	solve(res , root , cur , n-1);
	return res;*/
	return createTree(1 , n);
}

vector<TreeNode*> Solution::createTree(int start , int end)
{
	vector<TreeNode*> res;
	if(start > end){
		res.push_back(NULL);
		return res;
	}
	for(int k = start ; k <= end ; k++){
		vector<TreeNode*> leftTrees = createTree(start , k-1);
		vector<TreeNode*> rightTrees = createTree(k+1 , end);

		for(int i = 0 ; i < leftTrees.size() ; i++){
			for(int j = 0 ; j < rightTrees.size() ; j++){
				TreeNode *root = new TreeNode(k);
				root->left = leftTrees[i];
				root->right = rightTrees[j];
				res.push_back(root);
			}
		}
	}
	return res;
}

//cur 表示当前访问的节点指针
/*void Solution::solve(vector<TreeNode*>& res , TreeNode* root ,TreeNode* cur ,  int n)
{
	if(n == 0){
		res.push_back(root);
		return;
	}
	TreeNode node(n);
	cur->left = &node;
	TreeNode* tmpLeft = cur->left;
	solve(res , root , tmpLeft , n-1);
	
	cur->left = NULL;
	cur->right = &node;
	TreeNode* tmpRight = cur->right;
	solve(res , root , tmpRight , n-1);

	if(n > 1){
		TreeNode secNode(n-1);
		cur->left = &node;
		cur->right = &secNode;
		TreeNode* secTmpLeft = cur->left;
		TreeNode* secTmpRight = cur->right;
		solve(res , root , secTmpLeft , n-2);
		solve(res , root , secTmpRight , n-2);
	}
}*/
int main(int argc , char* argv[])
{
	Solution sol;
	vector<TreeNode*> res;
	res = sol.generateTrees(3);
	/*for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]->val<<" ";
	}*/
	cout<<"res.size() = "<<res.size()<<endl;
}
