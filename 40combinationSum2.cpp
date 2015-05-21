/*
 * =====================================================================================
 *
 *       Filename:  40combinationSum2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 09时06分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
	public:
		vector<vector<int> > combinationSum2(vector<int>& candidates , int target);
		void solve(vector<int>& condidates , int start , int target , vector<int>& item , vector<vector<int> >& res);
};

void Solution::solve(vector<int>& condidates , int start , int target , vector<int>& item , vector<vector<int> >& res)
{
	if(target < 0){
		return;
	}
	if(target == 0){
		res.push_back(item);
		return;
	}
	for(int i = start ; i < condidates.size() ; i++){
		if(i > start && condidates[i] == condidates[i-1]){
			continue;
		}
		item.push_back(condidates[i]);
		solve(condidates , i+1 , target-condidates[i] , item , res);
		item.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum2(vector<int>& candidates , int target)
{
	vector<vector<int> > res;
	if(candidates.size() <= 0){
		return res;
	}
	vector<int> vTmp;
	
	sort(candidates.begin() , candidates.end());
	solve(candidates , 0 , target , vTmp , res);
	return res;
}

int main(int argc ,char * argv[])
{
	vector<int> candidates;
	candidates.push_back(10);
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	
	Solution sol;

	vector<vector<int> > res;
	res = sol.combinationSum2(candidates , 8);

	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

