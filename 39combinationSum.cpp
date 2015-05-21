/*
 * =====================================================================================
 *
 *       Filename:  39combinationSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月20日 15时49分53秒
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
		vector<vector<int> > combinationSum(vector<int>& candidates , int target);
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
		if(i > 0 && condidates[i] == condidates[i-1]){
			continue;
		}
		item.push_back(condidates[i]);
		solve(condidates , i , target-condidates[i] , item , res);
		item.pop_back();
	}
}

vector<vector<int> > Solution::combinationSum(vector<int>& candidates , int target)
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
	candidates.push_back(2);
	candidates.push_back(3);
	candidates.push_back(6);
	candidates.push_back(7);
	
	Solution sol;

	vector<vector<int> > res;
	res = sol.combinationSum(candidates , 7);

	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

