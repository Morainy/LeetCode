/*
 * =====================================================================================
 *
 *       Filename:  35searchInsert.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 21时28分25秒
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

class Solution{
	public:
		int searchInsert(vector<int>& nums , int target);
};

int Solution::searchInsert(vector<int>& nums , int target)
{
	if(target<nums[0]){
		return 0;
	}
	if(target > nums[nums.size()-1]){
		return nums.size();
	}
	int start = 0 , end = nums.size()-1;
	while(start < end){
		int mid = (start+end)/2;
		if(nums[mid] < target && nums[mid+1] > target){
			return mid+1;
		}
		if(nums[mid] > target && nums[mid-1] < target){
			return mid;
		}
		else if(nums[mid]==target){
			return mid;
		}
		if(nums[mid] < target){
			start = mid+1;
		}
		else{
			end = mid-1;
		}
	}
}

int main(int argc , char * argv[])
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(6);

	Solution sol;
	int res = sol.searchInsert(v , 0);

	cout<<"res="<<res<<endl;
}
