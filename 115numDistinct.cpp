/*
 * =====================================================================================
 *
 *       Filename:  115numDistinct.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月22日 16时45分14秒
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
		int numDistinct(string s , string t);
};

int Solution::numDistinct(string s , string t)
{
	int m = s.length();
	int n = t.length();
	vector<vector<int> > res(m+1 , vector<int>(n+1 , 0));
	for(int i = 0 ; i < res.size() ; i++){
		res[i][0] = 1;
	}
	for(int i = 1 ; i < res.size() ; i++){
		for(int j = 1 ; j < res[i].size() ; j++){
			if(s[i-1] == t[j-1]){
				res[i][j] = res[i-1][j-1] + res[i-1][j];
			}else{
				res[i][j] = res[i-1][j];
			}
		}
	}
	return res[m][n];
}

int main(int argc , char* argv[])
{
	string s("rabbbit");
	string t("rabbit");
	Solution sol;
	cout<<"res = "<<sol.numDistinct(s , t)<<endl;
}
