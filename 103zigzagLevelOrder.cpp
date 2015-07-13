/*
 * =====================================================================================
 *
 *       Filename:  103zigzagLevelOrder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月13日 09时14分56秒
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
	vector<vector<int> >zigzagLevelOrder(TreeNode* root);
	void solve(vector<vector<int> >& res , vector<TreeNode*>& tmp , int levalCnt);
};

void Solution::solve(vector<vector<int> >& res , vector<TreeNode*>& tmp , int levalCnt)
{
	if(tmp.size() < 1){
		return;
	}
	vector<int> tmpval;
	vector<TreeNode*> tmpPtrs;
	if(levalCnt % 2 != 0){
		for (int i = tmp.size()-1 ; i >= 0 ; i--){
			if(tmp[i]){
				if(tmp[i]->left){
					tmpval.push_back(tmp[i]->left->val);
					tmpPtrs.push_back(tmp[i]->left);
				}
				if(tmp[i]->right){
					tmpval.push_back(tmp[i]->right->val);
					tmpPtrs.push_back(tmp[i]->right);
				}
			}
		}
	}else{
		for (int i = tmp.size()-1 ; i >= 0 ; i--){
			if(tmp[i]){
				if(tmp[i]->right){
					tmpval.push_back(tmp[i]->right->val);
					tmpPtrs.push_back(tmp[i]->right);
				}
				if(tmp[i]->left){
					tmpval.push_back(tmp[i]->left->val);
					tmpPtrs.push_back(tmp[i]->left);
				}
			}
		}
	}
	if(tmpval.size() > 0){
		res.push_back(tmpval);
	}
	solve(res , tmpPtrs , levalCnt+1);
}

vector<vector<int> >Solution::zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int> > res;
	vector<TreeNode*> tmp;
	if(!root){
		return res;
	}
	vector<int> tmpVal;
	tmp.push_back(root);
	tmpVal.push_back(root->val);
	res.push_back(tmpVal);
	solve(res , tmp , 0);
	return res;
}

int main(int argc , char* argv[])
{
	TreeNode node1(0);
	TreeNode node2(2);
	TreeNode node3(4);
	TreeNode node4(1);
	TreeNode node5(3);
	TreeNode node6(-1);
	TreeNode node7(5);
	TreeNode node5(3);
	
	TreeNode* root = &node1;
	node1.left = &node2;
	//node1.right = &node3;
	//node2.left = &node4;
	//node3.right = &node5;

	Solution sol;
	vector<vector<int> > res;
	res = sol.zigzagLevelOrder(root);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
