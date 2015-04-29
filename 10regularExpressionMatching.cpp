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
				j++;
				while(j < sLen && s.at(j) == s.at(j+1)){
					j++;
				}
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
			}
			else{
				j++;
			}
		}
	}
}
int main(int argc ,char *argv[])
{
	string str1("aab") , str2("c*a*b");
	Solution sol;
	bool res;
	res = sol.isMatch(str1 , str2);
	cout<<"res = "<<res<<endl;
}
