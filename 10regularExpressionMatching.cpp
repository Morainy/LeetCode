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
		bool solve(string s , string p , int i , int j);
};

/*bool Solution::isMatch(string s , string p)
{
	int i , j;
	int pLen = p.length();
	int sLen = s.length();
	if(sLen == 0 && pLen ==0){
		return true;
	}
	if(sLen == 0){
		if(pLen == 2){
			if(p.at(0) == '.'){
				if(p.at(1)== '*'){
					return true;
				}
			}
		}
		return false;
	}
	for(i = 0 , j = 0 ; i < pLen ; i++){
		if(p.at(i) == '.'){
			if(i+1 < pLen && p.at(i + 1) == '*'){
				if(p.substr(i + 2 , p.length() - (i+2)).length() <= 0){
					return true;
				}
				if(j +1 < sLen){
					return isMatch(s.substr(j +1 , s.length() - (j+1)) , p.substr(i + 2 , p.length() - (i+2)));
				}else{
					return false;
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
}*/

bool Solution::isMatch(string s , string p)
{
	return solve(s , p , 0 , 0);
}

bool Solution::solve(string s , string p , int i , int j)
{
	if(i == s.length() && j == p.length()){
		return true;
	}
	if(i == s.length() || j == p.length()){
		return false;
	}
	if(p.at(j) != '.' && p.at(j) != '*'){
		if(s.at(i) == p.at(j)){
			return solve(s , p , i+1 , j+1);
		}else{
			return false;
		}
	}
	if(p.at(j) == '.'){
		if(j+1 < p.length() && p.at(j+1) == '*'){
			if(solve(s , p , i , j+2)){
				return true;
			}else{
				
			}
		}
		return solve(s , p , i+1 , j+1);
	}
	if(p.at(j) == '*'){
		while(i < s.length() && s.at(i) == p.at(j-1)){
			i++;
		}
		return solve(s , p , i , j+1);
	}
}
int main(int argc ,char *argv[])
{
	string str1("aa") , str2(".*");
	Solution sol;
	bool res;
	res = sol.isMatch(str1 , str2);
	cout<<"res = "<<res<<endl;
}
