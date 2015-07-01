/*
 * =====================================================================================
 *
 *       Filename:  91numDecodings.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月30日 11时15分18秒
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
#include <vector>
using namespace std;

class Solution{
	public:
		int numDecodings(string s);
		int solve(string s);
};

int Solution::numDecodings(string s)
{
	return solve(s);
}
int Solution::solve(string s)
{
	/*int len = s.length();
	if(len == 0){
		return 0;
	}
	if(len == 1){
		if(s[0] == '0'){
			return 0;
		}
		return 1;
	}
	if(s[0] == '0'){
		return 0;
	}
	
	int d1 = s[0] - '0';
	int d2 = s[1] - '0';
	int d = d1*10 + d2;
	if(d <= 26){
		if(d == 10 | d == 20){
			if(len == 2){
				return solve(s.substr(2 , len -2)) + 1;
			}
			return solve(s.substr(2 , len -2));
		}
		else{
			return solve(s.substr(2 , len - 2)) + solve(s.substr(1 , len -1));
		}
	}else{
		return solve(s.substr(1 , len - 1));
	}*/
	
	int len = s.length();
	if(len == 0 || s[0] == '0'){
		return 0;
	}
	if(len == 1){
		if(s[0] == '0'){
			return 0;
		}else{
			return 1;
		}
	}
	vector<int> res;
	res.resize(len);
	int i = len-2;
	if(s[len-1] == '0'){
		res[len - 1] = 0;
	}else{
		res[len -1] = 1;
	}
	while(i >= 0){
		if(i == 0){
			if(s[i] == '0'){
				res[i] = 0;
				i--;
			}
		}
		if(s[i] == '0'){
			if(s[i-1] == '1' || s[i-1] == '2'){
				if(i+1 < len){
					res[i-1] = res[i] = res[i+1];
				}else{
					res[i-1] = res[i] = 1;
				}
				i -= 2;
				continue;
			}else{
				return 0;
			}
		}
		int b2 = s[i+1] - '0';
		int b1 = s[i] - '0';
		int b = b1*10 + b2;
		/*if(b < 10){
			if(i+1 < len){
				res[i] = res[i+1];
			}else{
				res[i] = 1;
			}
			i -= 1;
		}else if(b < 26){

		}*/
		if(b <= 26){
			if(i + 2 < len){
				res[i] = res[i+1] + res[i+2];
			}else{
				res[i] = res[i+1] + 1;
			}
			i--;
		}else{
			res[i] = res[i+1];
			i--;
		}
	}
	return res[0];
}

int main(int argc , char* argv[])
{
	Solution sol;
	//string s("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253");
	string s("26");
	int res = sol.numDecodings(s);
	cout<<"res = "<<res<<endl;
}

