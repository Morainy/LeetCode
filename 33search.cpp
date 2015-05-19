/*
 * =====================================================================================
 *
 *       Filename:  33search.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 15时18分16秒
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
		int search(vector<int>& nums , int targets);
};

int Solution::search(vector<int>& nums , int target)
{
	int res;
	int start = 0 , end = nums.size()-1;
	int mid;
	int pivot = 0;
	while(start <= end){
		mid = (start + end)/2;
		if(mid+1 < nums.size() && nums[mid]>nums[mid+1]){
			pivot = mid +1;
			break;
		}
		else{
			if(nums[mid]>=nums[0]){
				start = mid+1;
			}else{
				end = mid -1;
			}
		}
	}
	
	if(nums[0]==target){
		return 0;
	}
	if(nums[pivot] == target){
		return pivot;
	}
	if(nums[nums.size()-1]==target){
		return nums.size()-1;
	}
	if(pivot>0 && nums[pivot-1]==target){
		return pivot-1;
	}
	if(target > nums[pivot] && target < nums[nums.size()-1]){
		start = pivot;
		end = nums.size()-1;
	}
	else if(target>nums[0] && (pivot > 0 && target < nums[pivot-1])){
		start = 0;
		end = pivot-1;
	}
	else{
		return -1;
	}
	while(start <= end){
		mid = (start+end)/2;
		if(nums[mid]<target){
			start = mid + 1;
		}else if(nums[mid]>target){
			end = mid-1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
int main(int argc ,char * argv[])
{
	vector<int> v;
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	Solution sol;
	int res = sol.search(v , 1);
	cout<<"res="<<res<<endl;
}

