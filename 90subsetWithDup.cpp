/*
 * =====================================================================================
 *
 *       Filename:  90subsetWithDup.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月29日 15时54分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
	public:
		vector<vector<int> > subsetsWithDup(vector<int>& nums);
		void solve(set<vector<int> >& s ,  vector<int>& nums , vector<int>& tmp , int begin , int k);
};

void Solution::solve(set<vector<int> >& s ,  vector<int>& nums , vector<int>& tmp , int begin , int k)
{
	if(k == 0){
		s.insert(tmp);
		return;
	}
	if(k == 1){
		for(int i = begin ; i < nums.size() ; i++){
			tmp.push_back(nums[i]);
			s.insert(tmp);
			tmp.pop_back();
		}
		return;
	}
	for(int i = begin ; i < nums.size() ; i++){
		tmp.push_back(nums[i]);
		solve(s , nums , tmp , i+1 , k-1);
		tmp.pop_back();
	}

}
vector<vector<int> > Solution::subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin() , nums.end());
	set<vector<int> > s;
	vector<int> tmp;
	for(int i = 0 ; i <= nums.size() ; i++){
		solve(s , nums , tmp , 0 , i);
	}
	set<vector<int> >::iterator it = s.begin();
	vector<vector<int> > res;
	for(; it != s.end() ; it++){
		res.push_back(*it);
	}
	return res;
}

int main(int argc , char* argv[])
{
	int a[] = {4 , 1 , 0};
	int size = sizeof(a)/sizeof(a[0]);
	vector<int> v(a , a+size);
	Solution sol;
	vector<vector<int> > res;
	res = sol.subsetsWithDup(v);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

