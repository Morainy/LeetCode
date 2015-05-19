/*
 * =====================================================================================
 *
 *       Filename:  34searchRange.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 20时21分01秒
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
		vector<int> searchRange(vector<int>& nums , int target);
};

vector<int> Solution::searchRange(vector<int>& nums , int target)
{
	vector<int> res;
	int start = 0 , end = nums.size()-1;
	while(start <= end){
		int mid = (start+end)/2;
		if(nums[mid] > target){
			end = mid-1;
		}
		else if(nums[mid] < target){
			start = mid +1;
		}
		else{
			int startPos = mid , endPos = mid;
			while(startPos >0 && nums[startPos-1] == nums[startPos]){
				startPos--;
			}
			while(endPos<nums.size()-1 && nums[endPos]==nums[endPos+1]){
				endPos++;
			}
			res.push_back(startPos);
			res.push_back(endPos);
			return res;
		}
	}
	res.push_back(-1);
	res.push_back(-1);
	return res;
}
int main(int argc , char * argv[])
{
	Solution sol;
	vector<int> v;
	v.push_back(5);
	v.push_back(7);
	v.push_back(7);
	v.push_back(8);
	v.push_back(8);
	v.push_back(10);

	vector<int> res;
	res = sol.searchRange(v , 8);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

