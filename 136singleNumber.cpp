/*
 * =====================================================================================
 *
 *       Filename:  136singleNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月30日 20时36分22秒
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
		int singleNumber(vector<int>& nums);
};

int Solution::singleNumber(vector<int>& nums)
{
	int res = 0;
	for(int i = 0 ; i < nums.size() ; i++){
		res ^= nums[i];
	}
	return res;
}

int main(int argc , char* argv[])
{

}
