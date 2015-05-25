/*
 * =====================================================================================
 *
 *       Filename:  47permuteUnique.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月25日 08时42分59秒
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
#include <algorithm>
using namespace std;

class Solution{
	public:
		vector<vector<int> > permuteUnique(vector<int>& nums);
		void nextPermutation(vector<int>& nums);
		void swap(int& a , int& b);
};

vector<vector<int> > Solution::permuteUnique(vector<int>& nums)
{
	vector<vector<int> > res;
	if(nums.size() < 1){
		return res;
	}
	sort(nums.begin() , nums.end());
	res.push_back(nums);
	while(1){
		nextPermutation(nums);
		if(nums == res[0]){
			break;
		}else{
			res.push_back(nums);
		}
	}
	return res;
}
void Solution::swap(int& a , int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void Solution::nextPermutation(vector<int>& nums)
{
	int size = nums.size();
	vector<int>::iterator it1 ,it2;
	bool flag = false;
	for(it1 = nums.end()-1 ; it1 > nums.begin() ;it1--){
		if(*(it1-1)<*it1){
			flag = true;
			break;
		}
	}
	if(!flag){
		sort(nums.begin() , nums.end());
		return;
	}
	for(it2 = nums.end()-1 ; it2 >= it1 ; it2--){
		if(*it2 > *(it1-1)){
			swap(*(it1-1) , *it2);
			break;
		}
	}
	sort(it1,nums.end());
}	

int main(int argc , char * argv[])
{
	vector<vector<int> > res;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	//v.push_back(2);
	//v.push_back(3);

	Solution sol;
	res = sol.permuteUnique(v);

	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}

