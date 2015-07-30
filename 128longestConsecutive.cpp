/*
 * =====================================================================================
 *
 *       Filename:  128longestConsecutive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月30日 22时14分44秒
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
#include <algorithm>
using namespace std;

class Solution{
	public:
		int longestConsecutive(vector<int>& nums);
};

int Solution::longestConsecutive(vector<int>& nums)
{
	if(nums.size() == 0){
		return 0;
	}
	if(nums.size() == 1){
		return 1;
	}
	sort(nums.begin() , nums.end());
	nums.erase(unique(nums.begin() , nums.end()) , nums.end());
	int res = 1;
	int i = 0 , j , len;
	while(i < nums.size()){
		j = i;
		len = 0;
		while(j < nums.size() && nums[j] == nums[j+1]-1){
			j++;
			len++;
		}
		if(i != j){
			i = j;
			len++;
		}else{
			i++;
		}
		if(len > res){
			res = len;
		}
	}
	return res;
}

int main(int argc , char* argv[])
{
	Solution sol;
	vector<int> v;
	
	/*v.push_back(100);
	v.push_back(4);
	v.push_back(200);
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);*/

	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(1);

	int res = sol.longestConsecutive(v);

	cout<<"res = "<<res<<endl;

}
