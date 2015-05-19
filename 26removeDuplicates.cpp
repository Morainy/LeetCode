/*
 * =====================================================================================
 *
 *       Filename:  26removeDuplicates.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月13日 16时16分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution{
	public:
		int removeDuplicates(vector<int>& nums);
};

/*int Solution::removeDuplicates(vector<int>& nums)
{
	if(nums.size() < 2){
		return nums.size();
	}
	vector<int>::iterator start , end;
	vector<int>::iterator pos;
	bool flag = true;
	while(pos < nums.end()){
		pos = nums.begin();
		start = pos;
		while(pos < nums.end() && *pos == *(pos-1)){
			pos++;
		}
		end = pos;
		nums.erase(start+1 , end);
	}
	if( (nums.end() -2 >= nums.begin()) && *(nums.end() -2) == *(nums.end() -1)){
		nums.erase(nums.end() -1);
	}
	return nums.size();
}*/
int Solution::removeDuplicates(vector<int>& nums)
{
	nums.erase(unique(nums.begin() , nums.end()) , nums.end());
	return nums.size();
}
int main(int argc ,char * argv[])
{
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	//v.push_back(0);
	Solution sol;
	sol.removeDuplicates(v);
	for(int i = 0 ; i < v.size() ; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

/*#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums , int numsSize)
{
	int start , end;
	int pos = 0;
	while(pos < numsSize){
		start = pos;
		while(pos > 0 && pos < numsSize && nums[pos] == nums[pos-1]){
			pos++;
		}
		end = pos;
		memcpy(nums+start+1 , nums+end+1 , numsSize - end-1);
		numsSize = numsSize - (end - start +1);
	}
	return numsSize;
}
int main(int argc ,char * argv[])
{
	int nums[] = {1 ,1,2,2};
	int len = sizeof(nums)/sizeof(nums[0]);

	len = removeDuplicates(nums , len);

	for(int i = 0 ; i < len ; i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
}*/

