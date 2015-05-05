/*
 * =====================================================================================
 *
 *       Filename:  10regularExpressionMatching.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月27日 14时54分58秒
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
		bool isMatch(string s , string p);
};

bool Solution::isMatch(string s , string p)
{
	int i , j;
	int pLen = p.length();
	int sLen = s.length();
	for(i = 0 , j = 0 ; i < pLen ; i++){
		if(p.at(i) == '.'){
			if(i+1 < pLen && p.at(i + 1) == '*'){
				if(p.substr(i + 2 , p.length() - (i+2)).length() <= 0){
					return true;
				}
				return isMatch(s , p.substr(i + 2 , p.length() - (i+2)));
			}
			else{
				j++;
			}
		}
		else{
			if(i+1 < pLen && p.at(i+1) == '*'){
				while(j < sLen && s.at(j)==p.at(i)){
					j++;
				}
				i++;
				if(j >= sLen){
					int start = s.length() - (p.length() -(i + 1));
					int length = p.length() - (i +1);
					return isMatch(s.substr(start , length) , p.substr(i+1 , p.length() -(i+1)));
				}
			}
			else{
				if(j < sLen && p.at(i) == s.at(j)){
					j++;
				}
				else{
					return false;
				}
			}
		}
	}
	if(j < sLen || i < pLen){
		return false;
	}
	return true;
}
int main(int argc ,char *argv[])
{
	string str1("aaa") , str2("a*a");
	Solution sol;
	bool res;
	res = sol.isMatch(str1 , str2);
	cout<<"res = "<<res<<endl;
}
