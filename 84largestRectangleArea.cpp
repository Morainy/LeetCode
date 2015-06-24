/*
 * =====================================================================================
 *
 *       Filename:  84largestRectangleArea.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月23日 09时14分53秒
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
#include <stack>
using namespace std;

class Solution{
public:
	int largestRectangleArea(vector<int>& height);
};

int Solution::largestRectangleArea(vector<int>& height)
{
	height.push_back(0);
	int res = 0;
	stack<int> indexStack;
	for(int i = 0 ; i < height.size() ; i++){
		while(!indexStack.empty() && height[i] < height[indexStack.top()]){
			int top = indexStack.top();
			indexStack.pop();
			int nextTop = indexStack.size() == 0?-1:indexStack.top();
			int tmp = (i-nextTop-1)*height[top];
			if(res < tmp){
				res = tmp;
			}
		}
		indexStack.push(i);
	}
	return res;
}

int main(int argc , char* argv[])
{
	vector<int> height;
	for(int i = 0 ; i < 20000 ; i++){
		height.push_back(i);
	}
	/*height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);*/

	Solution sol;
	cout<<"res = "<<sol.largestRectangleArea(height)<<endl;
}
