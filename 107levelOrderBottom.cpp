/*
 * =====================================================================================
 *
 *       Filename:  107levelOrderBottom.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 16时30分24秒
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
		vector<vector<int> > levelOrderBottom(TreeNode* root);
		void solve(vector<vector<int> >& res , vector<TreeNode*>& nodes);
};

void Solution::solve(vector<vector<int> >& res , vector<TreeNode*>& nodes)
{
	if(nodes.size() < 1){
		return;
	}
	vector<TreeNode*> tmpNodes;
	vector<int> tmp;
	for(int i = 0 ; i < nodes.size() ; i++){
		if(nodes[i]->left){
			tmpNodes.push_back(nodes[i]->left);
			tmp.push_back(nodes[i]->left->val);
		}
		if(nodes[i]->right){
			tmpNodes.push_back(nodes[i]->right);
			tmp.push_back(nodes[i]->right->val);
		}
	}
	if(tmp.size() > 0){
		res.insert(res.begin() , tmp);
	}
	solve(res , tmpNodes);
}
vector<vector<int> > Solution::levelOrderBottom(TreeNode* root)
{
	vector<vector<int> > res;
	if(!root){
		return res;
	}
	vector<TreeNode*> tmpNodes;
	tmpNodes.push_back(root);
	vector<int> tmp;
	tmp.push_back(root->val);
	res.push_back(tmp);
	solve(res , tmpNodes);
	return res;
}

int main(int argc , char* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode* root = &node1;
	node1.right = &node2;
	
	Solution sol;
	vector<vector<int> > res;
	res = sol.levelOrderBottom(root);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

