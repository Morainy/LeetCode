/*
 * =====================================================================================
 *
 *       Filename:  31nextPermutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 08时58分44秒
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
		void nextPermutation(vector<int>& nums);
		void swap(int& a , int& b);
};

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
	vector<int>::iterator min = it1;
	for(it2= it1 ; it2 < nums.end() ;it2++){
		if((*it2-*(it1-1)) > 0 && *min > *it2-*(it1-1)){
			min = it2;
		}
	}
	swap(*(it1-1) , *min);
	sort(it1,nums.end());
}

int main(int argc ,char * argv[])
{
	Solution sol;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);

	sol.nextPermutation(v);
	for(int i = 0 ; i < v.size() ; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

