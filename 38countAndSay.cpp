/*
 * =====================================================================================
 *
 *       Filename:  38countAndSay.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月20日 14时49分55秒
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
		string countAndSay(int n);
};

string Solution::countAndSay(int n)
{
	string res;
	if(n < 1){
		return res;
	}
	if(n == 1){
		res = "1";
		return res;
	}
	string prevStr = "1";
	string currStr;

	for(int i = 0 ; i < n-1 ; i++){
		int j = 0;
		while(j < prevStr.length()){
			int count = 1;
			while(j+count < prevStr.length() && prevStr.at(j) == prevStr.at(j+count)){
				count++;
			}
			currStr.append(1 , '0'+count);
			currStr.append(1 , prevStr.at(j));
			j += count;
		}
		prevStr = currStr;
		currStr.clear();
	}
	return prevStr;
}

int main(int argc , char * argv[])
{
	Solution sol;
	int n;
	cin>>n;
	string str = sol.countAndSay(n);
	cout<<"str = "<<str<<endl;
}

