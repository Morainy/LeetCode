/*
 * =====================================================================================
 *
 *       Filename:  105buildTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月13日 10时59分02秒
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

/*class Solution{
	public:
		TreeNode* buildTree(vector<int>& preorder , vector<int>& inorder);
		void solve(TreeNode* root , vector<int>& preorder , vector<int>& inorder , int flag);
};

void Solution::solve(TreeNode* root , vector<int>& preorder , vector<int>& inorder , int flag)
{
	if(preorder.size() < 1){
		return;
	}
	if(preorder.size() == 1){
		if(flag == 0){
			root->left = new TreeNode(preorder[0]);
			return;
		}else{
			root->right = new TreeNode(preorder[0]);
			return;
		}
	}
	
	vector<int>::iterator it = find(inorder.begin() , inorder.end() , preorder[0]);
	if(it == inorder.end()){
		cout<<"输入不合法"<<endl;
		return;
	}
	vector<int> leftPreorder(preorder.begin() + 1 , preorder.begin() + 1 + (it - inorder.begin()));
	vector<int> rightPreorder(preorder.begin() + 1 + (it - inorder.begin()) , preorder.end());

	vector<int> leftInorder(inorder.begin() , it);
	vector<int> rightInorder(it+1 , inorder.end());
	solve(root->left , leftPreorder , leftInorder , 0);	//flag == 0 挂到左子树上
	solve(root->right , rightPreorder , rightInorder , 1);	//flag == 1 挂到右子树上
}
TreeNode* Solution::buildTree(vector<int>& preorder , vector<int>& inorder)
{
	TreeNode* root = NULL;
	if(preorder.size() != inorder.size()){
		return root;
	}
	if(preorder.size() < 1){
		return root;
	}
	if(preorder.size() == 1){
		root = new TreeNode(preorder[0]);
		return root;
	}
	vector<int>::iterator it = find(inorder.begin() , inorder.end() , preorder[0]);
	if(it == inorder.end()){
		cout<<"输入不合法"<<endl;
		return root;
	}
	root = new TreeNode(preorder[0]);
	vector<int> leftPreorder(preorder.begin() + 1 , preorder.begin() + 1 + (it - inorder.begin()));
	vector<int> rightPreorder(preorder.begin() + 1 + (it - inorder.begin()) , preorder.end());

	vector<int> leftInorder(inorder.begin() , it);
	vector<int> rightInorder(it+1 , inorder.end());
	solve(root , leftPreorder , leftInorder , 0);	//flag == 0 挂到左子树上
	solve(root , rightPreorder , rightInorder , 1);	//flag == 1 挂到右子树上
	return root;
}*/
class Solution{
	public:
		TreeNode* buildTree(vector<int>& preorder , vector<int>& inorder);
		template<typename Iter>
		TreeNode* make(Iter pFirst , Iter pLast , Iter iFirst , Iter iLast);
};
template<typename Iter>
TreeNode* Solution::make(Iter pFirst , Iter pLast , Iter iFirst , Iter iLast)
{
	if(pFirst == pLast){
		return NULL;
	}
	if(iFirst == iLast){
		return NULL;
	}
	int val = *pFirst;
	Iter iRoot = find(iFirst , iLast , val);
	TreeNode* root = new TreeNode(*iRoot);
	int leftSize = iRoot - iFirst;
	root->left = make(pFirst+1 , pFirst+leftSize+1 , iFirst , iRoot);
	root->right = make(pFirst+leftSize+1 , pLast , iRoot+1 , iLast);
	return root;
}

TreeNode* Solution::buildTree(vector<int>& preorder , vector<int>& inorder)
{
	int size = inorder.size();
	if(size == 0){
		return NULL;
	}
	return make(preorder.begin() , preorder.end() , inorder.begin() , inorder.end());
}
void pretraversal(TreeNode* root)
{
	if(!root){
		return;
	}
	cout<<root->val<<" ";
	pretraversal(root->left);
	pretraversal(root->right);
}
int main(int argc , char* argv[])
{
	vector<int> preorder;
	preorder.push_back(1);
	preorder.push_back(2);
	preorder.push_back(4);
	preorder.push_back(3);
	preorder.push_back(5);
	
	vector<int> inorder;
	inorder.push_back(4);
	inorder.push_back(2);
	inorder.push_back(1);
	inorder.push_back(3);
	inorder.push_back(5);

	Solution sol;
	TreeNode* root = sol.buildTree(preorder , inorder);
	pretraversal(root);
	cout<<endl;
	return 0;
}

