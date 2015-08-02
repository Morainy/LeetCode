/*
 * =====================================================================================
 *
 *       Filename:  129sumNumbers.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月30日 22时33分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
//#include <queue>
#include <stack>
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
		int sumNumbers(TreeNode* root);
		int solve(TreeNode* root , int res = 0);
};

int Solution::solve(TreeNode* root , int res)
{
	if(!root){
		return 0;
	}
	if(root->left || root->right){
		return solve(root->left , 10*res+root->val) + solve(root->right , 10*res+root->val);
	}else{
		return 10*res+root->val;
	}
}
int Solution::sumNumbers(TreeNode* root)
{
	/*int sum = 0;
	if(!root){
		return sum;
	}
	stack<TreeNode*> s;
	vector<int> v;
	s.push(root);
	while(!s.empty()){
		TreeNode* tmp = s.top();	//取出栈顶元素
		v.push_back(tmp->val);
		s.pop();
		if(tmp->right){
			s.push(tmp->right);
		}
		if(tmp->left){
			s.push(tmp->left);
		}
		if(!(tmp->left) && !(tmp->right)){
			for(int i = v.size() - 1 ; i >= 0 ; i--){
				sum += power(10 , v.size() -1 - i) * v[i];
			}
			v.pop_back();
		}
	}
	return sum;*/

	solve(root);
}

int main(int argc , char* argv[])
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);

	TreeNode* root = &node1;

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node3.right = &node5;

	Solution sol;
	int res = sol.sumNumbers(root);

	cout<<"res = "<<res<<endl;
}
