/*
 * =====================================================================================
 *
 *       Filename:  106buildTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月16日 10时30分17秒
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
#include <algorithm>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		TreeNode* buildTree(vector<int>& inorder , vector<int>& postorder);
		template<typename Iter>
		TreeNode* make(Iter iFirst , Iter iLast , Iter pFirst , Iter pLast);
};

template<typename Iter>
TreeNode* Solution::make(Iter iFirst , Iter iLast , Iter pFirst , Iter pLast)
{
	if(iFirst == iLast){
		return NULL;
	}
	if(pFirst == pLast){
		return NULL;
	}
	int val = *(pLast-1);
	Iter iRoot = find(iFirst , iLast , val);
	TreeNode* root = new TreeNode(val);
	int leftSize = iRoot - iFirst;
	root->left = make(iFirst , iRoot , pFirst , pFirst+leftSize);
	root->right = make(iRoot+1 , iLast , pFirst+leftSize , pLast-1);
	return root;
}

TreeNode* Solution::buildTree(vector<int>& inorder , vector<int>& postorder)
{
	if(inorder.size() == 0){
		return NULL;
	}
	return make(inorder.begin() , inorder.end() , postorder.begin() , postorder.end());
}

void preorderTraversal(TreeNode* root)
{
	if(!root){
		return;
	}
	cout<<root->val<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}
int main(int argc , char* argv[])
{
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(5);

	vector<int> postorder;
	postorder.push_back(4);
	postorder.push_back(2);
	postorder.push_back(5);
	postorder.push_back(3);
	postorder.push_back(1);

	Solution sol;
	TreeNode * root;
	root = sol.buildTree(inorder , postorder);
	preorderTraversal(root);
	cout<<endl;
}
