/*
 * =====================================================================================
 *
 *       Filename:  132minCut.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月03日 11时17分40秒
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
using namespace std;

class Solution{
	public:
		int minCut(string s);
};

int Solution::minCut(string s)
{
	int len = s.length();
	vector<int> dp(len + 1);
	vector<vector<bool> > p(len , vector<bool>(len + 1 , false));
	for(int i = 0 ; i <= len ; i++){
		dp[i] = i-1;
	}

	for(int i = 1 ; i <= len ; i++){
		for(int j = i - 1 ; j >= 0 ; j--){
			if(s[i-1] == s[j] && (i-j <= 2 || p[j+1][i-1])){
				p[j][i] = true;
				dp[i] = min(dp[i] , dp[j] + 1);
			}
		}
	}
	return dp[len];
}

int main(int argc , char* argv[])
{
	string str("aab");
	Solution sol;
	int res = sol.minCut(str);

	cout<<"res = "<<res<<endl;
}

