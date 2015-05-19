/*
 * =====================================================================================
 *
 *       Filename:  5longestPalindromicSubstring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月23日 19时37分24秒
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
using namespace std;

class Solution{
	public:
		string longestPalindrome(string s);
};

string Solution::longestPalindrome(string s)
{
	int length = s.length();
	if(length <= 1){
		return s;
	}
	int maxLength = 0 , start;
	bool table[1000][1000] = {false};
	for(int i = 0 ; i < length ; i++){
		table[i][i] = true;
		if(i < length -1 && s.at(i)==s.at(i+1)){
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	int len;
	for(len = 3 ; len <= length ; len++){
		for(int i = 0 ; i < length -len + 1 ; i++){
			int j = i + len - 1;
			if(table[i + 1][j-1] && s.at(i)==s.at(j)){
				table[i][j] = 1;
				start = i;
				maxLength = len;
			}
		}
	}
	return s.substr(start , maxLength);
}

int main(int argc ,char * argv[])
{
	string str("aaaa");
	Solution sol;
	string res = sol.longestPalindrome(str);
	cout<<"res =" <<res<<endl;
}
