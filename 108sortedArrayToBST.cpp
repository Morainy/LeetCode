/*
 * =====================================================================================
 *
 *       Filename:  108sortedArrayToBST.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 09时39分34秒
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
		TreeNode* sortedArrayToBST(vector<int>& nums);
		template<typename Iter>
		TreeNode* make(vector<int>& nums , Iter start , Iter end);
};

template<typename Iter>
TreeNode* Solution::make(vector<int>& nums , Iter start , Iter end)
{
	if(start == end){
		return NULL;
	}
	Iter iRoot = (start + end)/2;
	TreeNode* root = new TreeNode(nums[iRoot]);
	root->left = make(nums , start , iRoot);
	root->right = make(nums , iRoot+1 , end);
	return root;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums)
{
	if(nums.size() < 1){
		return NULL;
	}
	int size = nums.size();
	return make(nums , 0 , size);
}

void preorder(TreeNode* root)
{
	if(!root){
		return;
	}
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main(int argc , char* argv[])
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	Solution sol;
	TreeNode* root = sol.sortedArrayToBST(v);
	preorder(root);
	cout<<endl;
}

