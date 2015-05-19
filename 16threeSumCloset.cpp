/*
 * =====================================================================================
 *
 *       Filename:  16threeSumCloset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月06日 10时55分39秒
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
		int threeSumClosest(vector<int>& nums , int target);
};

int Solution::threeSumClosest(vector<int>& nums , int target)
{
	if(nums.size() < 3){
		return 0;
	}
	sort(nums.begin() , nums.end());
	int res = nums[0] + nums[1] + nums[2];
	int i , j , k;
	for(i = 0 ; i < nums.size() ; i++){
		j = i + 1;
		k = nums.size() -1;
		while(j < k){
			int sum = nums[i] + nums[j] + nums[k];
			if(abs(sum - target) < abs(res - target)){
				res = sum;
				/*j++;
				k--;
				continue;*/
			}
			if(sum == target){
				return sum;
			}
			else if(sum < target){
				j++;
			}
			else if(sum > target){
				k--;
			}
		}
	}
	return res;
}
int main(int argc , char * argv[])
{
	Solution sol;
	vector<int> v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-3);
	cout<<"res = "<<sol.threeSumClosest(v , 1)<<endl;
}

