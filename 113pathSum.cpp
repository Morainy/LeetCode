/*
 * =====================================================================================
 *
 *       Filename:  113pathSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月17日 14时48分00秒
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
		vector<vector<int> > pathSum(TreeNode* root , int sum);
};

vector<vector<int> > pathSum(TreeNode* root , int sum)
{
	vector<vector<int> > res;
}

int main(int argc , char* argv[])
{

}

