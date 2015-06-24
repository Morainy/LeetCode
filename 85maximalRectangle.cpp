/*
 * =====================================================================================
 *
 *       Filename:  85maximalRectangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月23日 15时55分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Solution{
	public:
	int maximalRectangle(vector<vector<char> >& matrix);
	int maxArea(vector<int> height);
};

int Solution::maxArea(vector<int> height)
{
	height.push_back(0);
	int res = 0;
	stack<int> s;
	for(int i = 0 ; i < height.size() ; i++){
		while(!s.empty() && height[i] < height[s.top()]){
			int top = s.top();
			s.pop();
			int nextTop = s.size() == 0?-1:s.top();
			int tmp = (i - nextTop -1)*height[top];
			if(res < tmp){
				res = tmp;
			}
		}
		s.push(i);
	}
	return res;
}
int Solution::maximalRectangle(vector<vector<char> >& matrix)
{
	if(matrix.size() < 1){
		return 0;
	}
	vector<vector<int> > height;
	for(int i = 0 ; i < matrix.size() ; i++){
		vector<int> tmp(matrix[i].size() , 0);
		for(int j = 0 ; j < matrix[i].size() ; j++){
			if(i == 0){
				if(matrix[i][j] == '1'){
					tmp[j] = 1;
				}else{
					tmp[j] = 0;
				}
			}else{
				if(matrix[i][j] == '0'){
					tmp[j] = 0;
				}else{
					tmp[j] = height[i-1][j] + 1;
				}
			}
		}
		height.push_back(tmp);
	}

	int res = 0;
	for(int i = 0 ; i < height.size() ; i++){
		int tmp = maxArea(height[i]);
		if(res < tmp){
			res = tmp;
		}
	}
	return res;
}

int main(int argc , char* argv[])
{
	vector<char> tmp;
	tmp.push_back('0');
	vector<vector<char> > matrix;
	matrix.push_back(tmp);

	Solution sol;
	cout<< "res = "<<sol.maximalRectangle(matrix)<<endl;
}

