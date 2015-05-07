/*
 * =====================================================================================
 *
 *       Filename:  18fourSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月07日 11时21分51秒
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

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target);
};

vector<vector<int> > Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int> > res;
	if (nums.size() < 4)
	{
		return res;
	}
	sort(nums.begin() , nums.end());
	int i ,j , start , end;
	for (i = 0 ; i < nums.size() ; i++)
	{
		if(i > 0 && nums[i] == nums[i-1]){
			continue;
		}
		for (j = i+1 ; j < nums.size() ; j++)
		{
			/*if(j == i){
				continue;
			}*/
			start = j + 1;
			end  = nums.size()-1;
			while(start < end){
				if(nums[i] + nums[j] + nums[start] + nums[end] == target){
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[j]);
					tmp.push_back(nums[start]);
					tmp.push_back(nums[end]);
					res.push_back(tmp);
					while(start < end && nums[start] == tmp[2]){
						start++;
					}
					while(start < end && nums[end] == tmp[3]){
						end--;
					}
				}
				else if(nums[i] + nums[j] + nums[start] + nums[end] < target){
					start++;
				}
				else{
					end--;
				}
			}
			while(j + 1 < nums.size() && nums[j+1]==nums[j]){
				j++;
			}
		}
		while(i + 1 <nums.size() && nums[i+1]== nums[i]){
			i++;
		}
	}
	return res;
}
int main(int argc ,char * argv[])
{

}

