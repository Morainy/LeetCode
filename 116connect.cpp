/*
 * =====================================================================================
 *
 *       Filename:  116connect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月23日 10时36分03秒
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

struct TreeLinkNode{
	int val;
	TreeLinkNode* left , *right , *next;
	TreeLinkNode(int x):val(x) , left(NULL) , right(NULL){}
};

class Solution{
	public:
		void connect(TreeLinkNode* root);
		void solve(vector<TreeLinkNode*>& tmp);
};

void Solution::solve(vector<TreeLinkNode*>& tmp)
{
	if(tmp.size() < 1){
		return;
	}
	vector<TreeLinkNode*> level;
	for(int i = 0 ; i <tmp.size() ; i++){
		if(tmp[i]->left){
			level.push_back(tmp[i]->left);
		}
		if(tmp[i]->right){
			level.push_back(tmp[i]->right);
		}
		if(i != (tmp.size()-1)){
			tmp[i]->next = tmp[i+1];
		}
	}
	solve(level);
}

void Solution::connect(TreeLinkNode* root)
{
	vector<TreeLinkNode*> tmp;
	if(!root){
		return;
	}
	tmp.push_back(root);
	solve(tmp);
}

int main(int argc , char* argv[])
{

}
