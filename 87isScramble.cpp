/*
 * =====================================================================================
 *
 *       Filename:  87isScramble.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月26日 19时26分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution{
	public:
		bool isScramble(string s1 , string s2);
};

bool Solution::isScramble(string s1 , string s2)
{
	string s1Str = s1;
	string s2Str = s2;
	sort(s1Str.begin() , s1Str.end());
	sort(s2Str.begin() , s2Str.end());
	if(s1Str != s2Str){
		return false;
	}
	if(s1.length() <= 1){
		return s1 == s2;
	}
	for(int i = 1 ; i < s1.length() ; i++){
		string s11 = s1.substr(0 , i);
		string s12 = s1.substr(i);
		string s21 = s2.substr(0 , i);
		string s22 = s2.substr(i);
		if(isScramble(s11 , s21) && isScramble(s12 , s22)){
			return true;
		}
		s21 = s2.substr(s2.size() - i);
		s22 = s2.substr(0 , s2.size() - i);
		if(isScramble(s11 , s21) && isScramble(s12 , s22)){
			return true;
		}
	}
	return false;
}

int main(int argc , char* argv[])
{
	string s1("ab");
	string s2("ba");
	Solution sol;
	cout<<"res = "<<sol.isScramble(s1 , s2)<<endl;
	return 0;
}
