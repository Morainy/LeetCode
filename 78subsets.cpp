/*
 * =====================================================================================
 *
 *       Filename:  subsets.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月16日 21时57分51秒
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

class Solution{
	public:
		vector<vector<int> > subsets(vector<int>& nums);
		void solve(vector<vector<int> >& res , vector<int>& tmp , vector<int>& nums , int begin , int k);
};

void Solution::solve(vector<vector<int> >& res , vector<int>& tmp , vector<int>& nums , int begin , int k)
{
	if(k == 0){
		res.push_back(tmp);
		return;
	}
	if(k == 1){
		for(int i = begin ; i < nums.size() ; i++){
			tmp.push_back(nums[i]);
			res.push_back(tmp);
			tmp.pop_back();
		}
		return;
	}
	for(int j = begin ; j <= nums.size()-k ; j++){
		tmp.push_back(nums[j]);
		vector<int> anotherTmp(tmp);
		solve(res , anotherTmp , nums , j+1 , k-1);
		tmp.pop_back();
	}
}
vector<vector<int> > Solution::subsets(vector<int>& nums)
{
	vector<vector<int> > res;
	vector<int> tmp;
	sort(nums.begin() , nums.end());
	nums.erase(unique(nums.begin() , nums.end()) , nums.end());
	for(int i = 0 ; i <= nums.size() ; i++){
		solve(res , tmp , nums , 0 , i);
	}
	return res;
}

int main(int argc , char* argv[])
{
	Solution sol;
	vector<vector<int> > res;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);

	res = sol.subsets(nums);

	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
