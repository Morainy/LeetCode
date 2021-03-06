/*
 * =====================================================================================
 *
 *       Filename:  77combine.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月16日 20时01分49秒
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

class Solution{
	public:
		vector<vector<int> > combine(int n , int k);
		void solve(vector<vector<int> > &res , vector<int>& tmp ,  vector<int>& nums , int begin , int k);
};

void Solution::solve(vector<vector<int> > &res ,vector<int>& tmp ,  vector<int>& nums , int begin , int k)
{
	if(k == 1){
		for(int i = begin ; i < nums.size() ; i++){
			tmp.push_back(nums[i]);
			res.push_back(tmp);
			tmp.pop_back();
		}
		return;
	}
	for(int j = begin ; j <= nums.size() -k ; j++){
		tmp.push_back(nums[j]);
		vector<int> anotherTmp(tmp);
		solve(res , anotherTmp , nums , j + 1 , k -1);
		tmp.pop_back();
	}
}

vector<vector<int> > Solution::combine(int n , int k)
{
	vector<vector<int> > res;
	vector<int> nums;
	for(int i = 1 ; i <= n ; i++){
		nums.push_back(i);
	}
	vector<int> tmp;
	solve(res , tmp , nums , 0 , k);
	return res;
}

int main(int argc , char* argv[])
{
	Solution sol;
	int n = 4 , k = 2;
	vector<vector<int> > res;
	res = sol.combine(n , k);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
