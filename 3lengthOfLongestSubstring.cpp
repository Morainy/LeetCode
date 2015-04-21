/*
 * =====================================================================================
 *
 *       Filename:  3lengthOfLongestSubstring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月21日 16时55分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

class Solution{
public:
	int lengthOfLongestSubstring(string s);
};

int Solution::lengthOfLongestSubstring(string s)
{
	int length = s.length();
	if(!length){
		return 0;
	}
	int array[256];
	memset(array ,-1 , 256 * 4);
	int res = 0;
	int i  = 0 , j;
	int count;
	while(i < length){
		count = 0;
		for(j = i ; j <length ; j++){
			if(array[s.at(j)] < 0){
				array[s.at(j)] = j;
				count++;
			}
			else{
				i = array[s.at(j)] + 1;
				memset(array , -1 , 256 * 4);
				break;
			}
		}
		if(count > res){
			res = count;
		}
		if(j < length){
			continue;
		}
		else{
			break;
		}
	}
	return res;
}

int main(int argc ,char * argv[])
{
	string str("c");
	Solution sol;
	
	cout<<"res = "<<sol.lengthOfLongestSubstring(str)<<endl;
}
