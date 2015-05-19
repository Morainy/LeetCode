/*
 * =====================================================================================
 *
 *       Filename:  14longestCommonPrefix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月29日 20时43分47秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

class Solution{
	public:
		string longestCommonPrefix(vector<string> & strs);
};

string Solution::longestCommonPrefix(vector<string> &strs)
{
	int max = 0;
	string maxStr;
	if(strs.size() <= 0){
		return maxStr;
	}
	max = strs[0].length();
	int i;
	for(i = 1 ; i < strs.size() ; i++){
		while(max > 0){
			if(max > strs[i].length()){
				max = strs[i].length();
			}
			while(strs[i].substr(0 , max) != strs[0].substr(0 , max)){
				max--;
			}
			if(strs[i].substr(0 , max) == strs[0].substr(0 , max)){
				break;
			}
		}
	}
	
	maxStr = strs[0].substr(0 , max);
	return maxStr;
}

int main(int argc ,char * argv[])
{
	Solution sol;
	string str1 = "aac" , str2 = "a" , str3 = "ccc";
	vector<string> strs;
	strs.push_back(str1);
	strs.push_back(str2);
	strs.push_back(str3);

	cout<<sol.longestCommonPrefix(strs)<<endl;
}
