/*
 * =====================================================================================
 *
 *       Filename:  15threeSum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月05日 15时18分18秒
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
		vector<vector<int> > threeSum(vector<int>& nums);
};

vector<vector<int> > Solution::threeSum(vector<int>& nums)
{
	vector<vector<int> > res;
	if(nums.size() < 3){
		return res;
	}
	sort(nums.begin() , nums.end());
	int i , j , k;
	for(i = 0 ; i < nums.size() ; i++){
		if(i > 0 && nums[i] == nums[i-1]){
			continue;
		}
		j = i + 1 ;
		k = nums.size() - 1;
		while(j < k){
			if(nums[j] + nums[k] + nums[i] == 0){
				int end = res.size() -1;
				if(end >= 0 && res[end][0] == nums[i] && res[end][1] == nums[j] && res[end][2] == nums[k]){
					j++;
					k--;
					continue;
				}
				vector<int> tmp;
				tmp.push_back(nums[i]);
				tmp.push_back(nums[j]);
				tmp.push_back(nums[k]);
				res.push_back(tmp);
				j++;
				k--;
			}
			else if((nums[j] + nums[k]) < -nums[i]){
				j++;
			}
			else{
				k--;
			}
		}
	}
	/*vector<vector<int> >::iterator end_unique = unique(res.begin() , res.end());
	res.erase(end_unique , res.end());*/
	return res;
}

int main(int argc ,char * argv[])
{
	vector<int> v;
	v.push_back(-2);
	v.push_back(0);
	v.push_back(0);
	v.push_back(2);
	v.push_back(2);
	Solution sol;
	vector<vector<int> > result;
	result = sol.threeSum(v);
	for(int i = 0 ; i < result.size() ; i++){
		for(int j = 0 ; j < result[i].size() ; j++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}
