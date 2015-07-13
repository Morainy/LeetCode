/*
 * =====================================================================================
 *
 *       Filename:  102levelOrder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月07日 10时34分41秒
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
		vector<vector<int> > levelOrder(TreeNode* root);
		void solve(vector<vector<int> >& res , vector<TreeNode*>& tmp);
};

void Solution::solve(vector<vector<int> >& res ,vector<TreeNode*>& tmp)
{
	if(tmp.size() < 1){
		return;
	}
	vector<TreeNode*> newTmp;
	vector<int> valTmp;
	for(int i = 0 ; i < tmp.size() ; i++){
		if(tmp[i]->left){
			newTmp.push_back(tmp[i]->left);
			valTmp.push_back(tmp[i]->left->val);

		}
		if(tmp[i]->right){
			newTmp.push_back(tmp[i]->right);
			valTmp.push_back(tmp[i]->right->val);
		}
	}
	if(valTmp.size() > 0){
		res.push_back(valTmp);
	}
	solve(res , newTmp);
}

vector<vector<int> > Solution::levelOrder(TreeNode* root)
{
	vector<vector<int> > res;
	if(!root){
		return res;
	}
	vector<int> tmp;
	vector<TreeNode*> nodeTmp;
	tmp.push_back(root->val);
	res.push_back(tmp);
	nodeTmp.push_back(root);
	solve(res ,nodeTmp);
	return res;
}

int main(int argc , char* argv[])
{
	vector<vector<int> > res;
	TreeNode node1(3);
	TreeNode node2(9);
	TreeNode node3(20);
	TreeNode node4(15);
	TreeNode node5(7);
	TreeNode node6(1);
	TreeNode node7(2);
	
	TreeNode* root = &node1;
	node1.left = &node2;
	node1.right = &node3;
	node3.left = &node4;
	node3.right = &node5;
	node2.left = &node6;
	node2.right = &node7;

	Solution sol;
	res = sol.levelOrder(root);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

