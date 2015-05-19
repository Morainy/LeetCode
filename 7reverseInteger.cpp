/*
 * =====================================================================================
 *
 *       Filename:  7reverseInteger.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月24日 15时56分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Solution{
	public:
		int reverse(int x);
};

int Solution::reverse(int x)
{
	if(x == 0){
		return 0;
	}
	int xTemp = x;
	if(x < 0){
		xTemp = -xTemp;
	}
	char str[20] = {0};
	sprintf(str , "%d", xTemp);
	int res = 0;
	int len = strlen(str);
	int i;
	for(i = len -1 ; i >= 0 ; i--){
		if(i == len -1){
			while(str[i] == '0' && i >= 0){
				i--;
			}
		}
		if((((0x7fffffff) - (str[i] - '0')) / 10) < res) {
			return 0;
		}
		res = 10 * res + (str[i]- '0');
	}
	if(x < 0){
		res = -res;
	}
	return res;
}

int main()
{
	Solution sol;
	int res = sol.reverse(-2147483412);
	cout<<"res = "<<res<<endl;
}
