/*
 * =====================================================================================
 *
 *       Filename:  27removeElement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月14日 20时16分01秒
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
		int removeElement(vector<int>& nums , int val);
};

int Solution::removeElement(vector<int>& nums , int val)
{
	vector<int>::iterator pos;
	while(1){
		pos = nums.begin();
		while(pos != nums.end()){
			if(*pos == val){
				nums.erase(pos);
				break;
			}
			else{
				pos++;
			}
		}
		if(pos == nums.end()){
			break;
		}
	}
	return nums.size();
}
int main(int argc ,char * argv[])
{
	vector<int> nums;
	nums.push_back(2);
	Solution sol;
	sol.removeElement(nums , 3);

	for(int i = 0 ; i < nums.size() ; i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}

