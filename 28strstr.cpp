/*
 * =====================================================================================
 *
 *       Filename:  28strstr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月14日 20时27分14秒
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
using namespace std;

class Solution{
	public:
		int strStr(string haystack , string needle);
};

int Solution::strStr(string haystack , string needle)
{
	if(haystack.length() == 0 && needle.length() == 0){
		return 0;
	}
	if(haystack.length() < needle.length()){
		return -1;
	}
	int i , j;
	for(i = 0 ; i <= (haystack.length() - needle.length()) ; i++){
		for(j = 0 ; j < needle.length() ; j++){
			if(haystack.at(i+j) != needle.at(j)){
				break;
			}
		}
		if(j == needle.length()){
			return i;
		}
	}
	return -1;
}

int main(int argc ,char *argv[])
{
	string str1("a") , str2("a");
	Solution sol;
	int res = sol.strStr(str1 , str2);
	cout<<"res = " <<res<<endl;
}

