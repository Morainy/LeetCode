/*
 * =====================================================================================
 *
 *       Filename:  81search.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月19日 15时56分03秒
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
		bool search(vector<int>& nums , int target);
};
bool Solution::search(vector<int>& nums , int target)
{
	if(nums.size() < 1){
		return false;
	}
	int len = nums.size();
	int start = 0 , end = len-1;
	int mid;
	
	while(start <= end){
		mid = (start + end)/2;
		if(target == nums[start] || target == nums[end]){
			return true;
		}
		if(nums[mid] == nums[start] && nums[mid]== nums[end]){
			start++;
			end--;
			continue;
		}
		if(nums[mid] <= nums[end]){
			if(nums[mid] <= target && target <= nums[end]){
				int rlow = mid , rhigh = end;
				while(rlow <= rhigh){
					int rmid = (rlow + rhigh)/2;
					if(nums[rmid] < target){
						rlow = rmid + 1;
					}else if(nums[rmid] > target){
						rhigh = rmid -1;
					}else{
						return true;
					}
				}
			}
			end = mid - 1;
		}
		if(nums[start] <= nums[mid]){
			if(nums[start] <= target && target <= nums[mid]){
				int llow = start , lhigh = mid;
				while(llow <= lhigh){
					int lmid = (llow + lhigh) / 2;
					if(nums[lmid] < target){
						llow = lmid + 1;
					}else if(nums[lmid] > target){
						lhigh = lmid -1;
					}else{
						return true;
					}
				}
			}
			start = mid + 1;
		}
	}
	return false;
}

int main(int argc , char * argv[])
{
	vector<int> v;
	/*v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);*/
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);

	Solution sol;
	cout<<"res = " << sol.search(v , 0)<<endl;
}
