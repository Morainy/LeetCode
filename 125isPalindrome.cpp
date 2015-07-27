/*
 * =====================================================================================
 *
 *       Filename:  125isPalindrome.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月27日 20时49分07秒
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
		bool isPalindrome(string s);
		bool isPunctuations(const char s);
};

bool Solution::isPunctuations(char ch)
{
	if(ch >= '0' && ch <= '9'){
		return false;
	}
	if(ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a')){
		return true;
	}else{
		return false;
	}
}

bool Solution::isPalindrome(string s)
{
	int len = s.length();
	if(len < 1){
		return true;
	}
	int i = 0 , j = len-1;
	while(i < j){
		if(isPunctuations(s[i])){
			i++;
			continue;
		}
		if(isPunctuations(s[j])){
			j--;
			continue;
		}
		if(s[i] == s[j] || s[j]-s[i] == 32 || s[i]-s[j] == 32){
			i++;
			j--;
		}else{
			return false;
		}
	}
	return true;
}

int main(int argc , char* argv[])
{
	//string str("A man, a plan, a canal: Panama");
	string str("1a2");
	Solution sol;
	cout<<"res = "<<sol.isPalindrome(str)<<endl;
}
