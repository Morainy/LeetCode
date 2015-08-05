/*
 * =====================================================================================
 *
 *       Filename:  131partition.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月03日 10时47分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
	public:
		vector<vector<string> > partition(string s);
		bool isPalindrome(string::iterator begin , string::iterator end);
		void solve(vector<vector<string> >& res , vector<string>& tmp , string::iterator start , string& s);
};

void Solution::solve(vector<vector<string> >& res , vector<string>& tmp , string::iterator start , string& s)
{
	if(start == s.end()){
		res.push_back(tmp);
		return;
	}
	for(int i = 0 ; start + i != s.end() ; i++){
		if(isPalindrome(start , start+i)){
			tmp.push_back(s.substr(start-s.begin() , i+1));
			solve(res , tmp , start+i+1 , s);
			tmp.pop_back();
		}
	}
}

bool Solution::isPalindrome(string::iterator begin , string::iterator end)
{
	while(begin < end){
		if(*begin != *end){
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

vector<vector<string> > Solution::partition(string s)
{
	vector<vector<string> > res;
	vector<string> tmp;
	solve(res , tmp , s.begin() , s);
	return res;
}

int main(int argc , char* argv[])
{
	string str("aab");
	Solution sol;
	vector<vector<string> > res;
	res = sol.partition(str);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
