/*
 * =====================================================================================
 *
 *       Filename:  80removeDuplicates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月19日 15时41分15秒
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
		int removeDuplicates(vector<int>& nums);
};

int Solution::removeDuplicates(vector<int>& nums)
{
	int start = 0 , j;
	vector<int> tmp;
	for(j = 0 ; j < nums.size() ; j++){
		if(nums[start] != nums[j]){
			if(j - start <= 2){
				for(int k = 0 ; k < j - start ; k++){
					tmp.push_back(nums[start]);
				}
			}else{
				tmp.push_back(nums[start]);
				tmp.push_back(nums[start]);
			}
			start = j;
		}
	}
	if(j - start > 2){
		tmp.push_back(nums[start]);
		tmp.push_back(nums[start]);
	}else{
		for(int k = start ; k < j ;k++){
			tmp.push_back(nums[k]);
		}
	}
	nums = tmp;
	return tmp.size();
}

int main(int argc , char * argv[])
{

}
