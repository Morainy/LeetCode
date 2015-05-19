/*
 * =====================================================================================
 *
 *       Filename:  17letterCombinations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月06日 11时31分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution{
	public:
		vector<string> letterCombinations(string digits);
};

vector<string> Solution::letterCombinations(string digits)
{
	if(digits.length() <= 0){
		vector<string> res;
		return res;
	}
	vector<string> res(1 , "");
	string map[] = {" " , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
	int i , j , k;
	for(i = 0 ; i < digits.length() ; i++){
		vector<string> tmp;
		for(j = 0 ; j < res.size() ; j++){
			for(k = 0 ; k < map[digits.at(i) - '0'].length() ; k++){
				tmp.push_back(res[j] + map[digits.at(i)-'0'][k]);
			}
		}
		res = tmp;
	}
	return res;
}
int main(int argc , char * argv[])
{
	string str("23");
	Solution sol;
	vector<string> result;
	result = sol.letterCombinations(str);
	for(int i = 0 ; i < result.size() ; i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}

