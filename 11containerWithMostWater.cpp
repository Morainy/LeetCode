/*
 * =====================================================================================
 *
 *       Filename:  11containerWithMostWater.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月28日 11时04分35秒
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
		int maxArea(vector<int>& height);
		int min(int a , int b)
		{
			return a<b?a:b;
		}
		int max(int a , int b)
		{
			return a>b?a:b;
		}
};

int Solution::maxArea(vector<int>&height)
{
	int res = 0;
	int size = height.size();
	int i = 0 , j = size-1;
	while(j > i){
		res = max(res , min(height[i],height[j])*(j-i));
		if(height[i]<height[j]){
			i++;
		}
		else{
			j--;
		}
	}
	return res;
}
int main(int argc ,char *argv[])
{

}
