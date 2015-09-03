/*
 * =====================================================================================
 *
 *       Filename:  139wordBreak.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年09月02日 21时03分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

class Solution{
	public:
		bool wordBreak(string s , unordered_set<string>& wordDict);
};

bool Solution::wordBreak(string s , unordered_set<string>& wordDict)
{
	/*if(s.length() < 1){
		return false;
	}
	queue<string> q;
	unordered_set<string>::iterator it;
	q.push(s);
	while(!q.empty()){
		string str = q.front();
		q.pop();
		for(it = wordDict.begin() ; it != wordDict.end() ; it++){
			int itTmp;
			itTmp = str.find(*it , 0);
			if(itTmp < 0){
				continue;
			}
			if(itTmp != 0){
				string strRes = str.substr(0 , itTmp);
				q.push(strRes);
			}
			if(itTmp + (*it).length() != str.length()){
				string strRes = str.substr(itTmp + (*it).length() , str.length() - itTmp);
				q.push(strRes);
			}
			q.push("#");
			//break;
		}
		if(it == wordDict.end()){
			while(!q.empty()){
				if(q.front() == "#"){
					q.pop();
					break;
				}
				q.pop();
			}
			if(q.empty()){
				return false;
			}
		}
	}
	return true;
	*/
	if(s.empty() || wordDict.empty()){
		return false;
	}

	vector<int> dp(s.size()+1 , 0);
	dp[0] = 1;

	for(int i = 1 ; i <= s.size() ; i++){
		for(int j = i-1 ; j >= 0 ; j--){
			if(dp[j] && wordDict.find(s.substr(j , i - j)) != wordDict.end()){
				dp[i] = 1;
				break;
			}
		}
	}

	return dp[s.size()];
}

int main(int argc , char* argv[])
{
	string str("dogs");
	unordered_set<string> set;
	set.insert("dog");
	set.insert("s");
	set.insert("gs");

	Solution sol;
	cout<<"res = "<<sol.wordBreak(str , set)<<endl;
}
