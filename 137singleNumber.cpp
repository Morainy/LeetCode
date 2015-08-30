/*
 * =====================================================================================
 *
 *       Filename:  137singleNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月30日 20时39分37秒
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
		int singleNumber(vector<int>& nums);
};

int Solution::singleNumber(vector<int>& nums)
{
	sort(nums.begin() , nums.end());
	int i = 0;
	while(i < nums.size()){
		if(i+1 < nums.size() && nums[i] == nums[i+1]){
			i = i + 3;
		}else{
			return nums[i];
		}
	}
	return nums[i];
}



int main(int argc , char* argv[])
{

}
