/*
 * =====================================================================================
 *
 *       Filename:  45jump.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月23日 09时15分10秒
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
using namespace std;

/*class Solution{
	public:
		int jump(vector<int>& nums);
		int solve(vector<vector<int> >& table , int i , int step);
};

int Solution::jump(vector<int>& nums)
{
	if(nums.size() <= 1){
		return 0;
	}
	vector<vector<int> > table;
	for(int i = 0 ; i < nums.size()-1 ;i++){
		vector<int> row;
		for(int j = 0 ; j <= nums[i] ; j++){
			row.push_back(i+j);
		}
		table.push_back(row);
	}

	return solve(table , 0 , 0); 
}

//检测从第i个元素是否能走到最后一个元素，step为已经走过的步数
int Solution::solve(vector<vector<int> >& table , int i , int step)
{
	if(i == (table.size())){
		return step;
	}
	if(step > table.size()){
		return -1;
	}
	for(int j = 1 ; j < table[i].size() ; j++){
		if(table[i][j] == table.size()){
			return step + 1;
		}
	}
	int minStep = table.size();
	for(int j = 1 ; j < table[i].size() ; j++){
		if(table[i][j] >= table.size()){
			continue;
		}
		int res = solve(table , table[i][j] , step+1);
		if(res < minStep){
			minStep = res;
		}
	}
	return minStep;
}*/

class Solution{
	public:
		int jump(vector<int>& nums);
};

int Solution::jump(vector<int>& nums)
{
	int res = 0;
	int last = 0;
	int cur = 0;
	for(int i = 0 ; i < nums.size() ; i++){
		if(i > last){
			last = cur;
			res++;
		}
		if(i+nums[i] > cur){
			cur = i+nums[i];
		}
	}
	return res;
}
int main(int argc , char * argv[])
{
	Solution sol;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(4);

	int res = sol.jump(v);
	cout<<"res = "<<res<<endl;
}

