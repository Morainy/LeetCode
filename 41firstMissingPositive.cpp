/*
 * =====================================================================================
 *
 *       Filename:  41firstMissingPositive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 09时37分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Morain 
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
		int firstMissingPositive(vector<int>& nums);
};

int Solution::firstMissingPositive(vector<int>& nums)
{
	if(nums.size() <= 0){
		return 1;
	}
	sort(nums.begin() , nums.end());
	int res = 0;
	int i;
	bool flag = true;		//标记是否第一次遇见正值
	for(i = 0 ; i < nums.size() ; i++){
		if(i > 0 && nums[i]==nums[i-1]){
			continue;
		}
		if(flag){
			if(nums[i]>0){
				flag = false;
				if(nums[i] != 1){
					res = 1;
					return res;
				}
			}
		}
		if(i > 0 && nums[i-1] > 0 && nums[i]-nums[i-1] != 1){
			res = nums[i-1]+1;
			return res;
		}
	}
	return nums[i-1]+1;
}

int main(int argc , char* argv[])
{
	Solution sol;
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(1);

	int res = sol.firstMissingPositive(v);

	cout<<"res="<<res<<endl;
}
