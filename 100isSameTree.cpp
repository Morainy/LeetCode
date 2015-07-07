/*
 * =====================================================================================
 *
 *       Filename:  100isSameTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月07日 08时58分51秒
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
		bool isSameTree(TreeNode* p , TreeNode* q);
};

bool Solution::isSameTree(TreeNode* p , TreeNode* q)
{
	if(!p && !q){
		return true;
	}
	if( (!p||!q) || p->val != q->val){
		return false;
	}else{
		return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
	}
}

int main(int argc , char* argv[])
{

}

