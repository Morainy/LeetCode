/*
 * =====================================================================================
 *
 *       Filename:  44isMatch.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月21日 16时51分16秒
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
		bool isMatch(string s , string p);
		bool solve(string s , string p , int i ,int j);
};
bool Solution::isMatch(string s , string p)
{
	return solve(s , p , 0 , 0);
}

/*bool Solution::solve(string s , string p , int i , int j)
{
	if(i == s.length() && j == p.length()){
		return true;
	}
	if(i == s.length() || j == p.length()){
		return false;
	}
	if(p.at(j) != '?' && p.at(j) != '*'){
		if(s.at(i) == p.at(j)){
			return solve(s , p , i+1 , j+1);
		}else{
			return false;
		}
	}
	if(p.at(j) == '?'){
		return solve(s , p , i+1 , j+1);
	}
	if(p.at(j) == '*'){
		if(solve(s , p , i , j+1)){
			return true;
		}else{
			return solve(s , p , i+1 , j);
		}
	}
}*/
bool Solution::solve(string s , string p , int i , int j)
{
	if(j == p.length()){
		return i == s.length();
	}
	if(i == s.length() || j == p.length()){
		return false;
	}
	if(p.at(j) == '*'){
		while(p.at(j) == '*'){
			j++;
		}
		while(i < s.length()){
			if(solve(s , p , i , j)){
				return true;
			}
			i++;
		}
		return solve(s , p , i , j);
	}
	else if(i < s.length() && (p.at(j) == '?' || s.at(i)==p.at(j))){
		return solve(s , p , i+1 , j+1);
	}
	return false;
}

int main(int argc , char * argv[])
{
	string str1("abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab") , str2("*aabb***aa**a******aa*");
	Solution sol;
	cout<<"res="<<sol.isMatch(str1 , str2)<<endl;
}

