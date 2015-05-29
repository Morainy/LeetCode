/*
 * =====================================================================================
 *
 *       Filename:  55canjump.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月28日 15时40分14秒
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
		bool canJump(vector<int>& nums);
};

bool Solution::canJump(vector<int>& nums)
{
	if(nums.size() <= 1){
		return true;
	}
	int cur = 0;
	for(int i = 0 ; i < nums.size()-1 ; i++){
		/*if(cur == 0){
			return false;
		}*/
		if(i <= cur){
			if( (i + nums[i]) > cur){
				cur = i + nums[i];
				if(cur >= nums.size()-1){
					return true;
				}
			}
		}else{
			return false;
		}
	}
	return false;
}

int main(int argc , char * argv[])
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	//v.push_back(3);
	//v.push_back(1);
	v.push_back(4);

	Solution sol;
	cout<<sol.canJump(v)<<endl;

}
