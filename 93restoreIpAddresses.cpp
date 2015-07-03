/*
 * =====================================================================================
 *
 *       Filename:  93restoreIpAddresses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月02日 10时26分03秒
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
		vector<string> restoreIpAddresses(string s);
		void solve(vector<string>& res ,string& resTmp , string s , int begin);
};

vector<string> Solution::restoreIpAddresses(string s)
{
	vector<string> res;
	int len = s.length();
	if(len < 4){
		return res;
	}
	string tmp;
	solve(res , tmp , s , 0);
	return res;
}
void Solution::solve(vector<string>& res , string& resTmp , string s , int begin)
{
	int dotCnt = 0;
	for(int i = 0 ; i < resTmp.length() ; i++){
		if(resTmp[i] == '.'){
			dotCnt++;
		}
	}
	int sLen = s.length();
	if(sLen == begin){
		return;
	}
	if(dotCnt == 3 && sLen - begin > 3){
		return;
	}
	if(dotCnt == 3 && sLen - begin <= 3){
		if(sLen - begin == 0){
			return;
		}
		if(sLen - begin == 1 || sLen - begin == 2){
			if(sLen - begin == 2){
				int d = s[begin] - '0';
				if(d == 0){
					return;
				}
			}
			resTmp += s.substr(begin , sLen - begin);
			res.push_back(resTmp);
			return;
		}
		if(sLen - begin == 3){
			int d1 = s[begin] - '0';
			if(d1 == 0){
				return;
			}
			int d2 = s[begin + 1] - '0';
			int d3 = s[begin + 2] - '0';
			int d = d1 * 100 + d2 * 10 + d3;
			if(d <= 255){
				resTmp += s.substr(begin , sLen - begin);
				res.push_back(resTmp);
				return;
			}else{
				return;
			}
		}
	}

	string resTmp1(resTmp);
	resTmp1 += s.substr(begin , 1);
	resTmp1 += ".";
	solve(res , resTmp1 , s , begin+1);

	if(sLen - begin >= 2){
		string resTmp2(resTmp);
		int d21 = s[begin] - '0';
		if(d21 == 0){
			return;
		}
		resTmp2 += s.substr(begin , 2);
		resTmp2 += ".";
		solve(res , resTmp2 , s , begin + 2);

		if(sLen - begin >= 3){
			string resTmp3(resTmp);
			int d1 = s[begin] - '0';
			if(d1 == 0){
				return;
			}
			int d2 = s[begin + 1] - '0';
			int d3 = s[begin + 2] - '0';
			int d = d1 * 100 + d2 * 10 + d3;
			if(d <= 255){
				resTmp3 += s.substr(begin , 3);
				resTmp3 += ".";
				solve(res , resTmp3 , s , begin + 3);
			}
		}
	}
}

int main(int argc , char* argv[])
{
	//string str("25525511135");
	string str("00000");
	Solution sol;
	vector<string> res;
	res = sol.restoreIpAddresses(str);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<endl;
	}
}

