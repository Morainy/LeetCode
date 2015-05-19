/*
 * =====================================================================================
 *
 *       Filename:  168ExcelSheetColumnNumber.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月13日 16时07分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Solution{
	public:
		string convertToTitle(int n);
};

string Solution::convertToTitle(int n)
{
	string res;
	while(n>0){
    int tail = n % 26; 
    if(tail == 0){
    tail = 26;   
    res = 'Z' + res;
    }
	else{
		char c = 'A' + tail - 1;
		res = c + res;
	}
    n = n - tail; 
    n = n / 26; 
    }
	return res;
}
int main(int argc ,char *argv[])
{
	Solution s;
	int num;
	cout<<"Please input the number:"<<endl;
	while(cin>>num){
		cout<<s.convertToTitle(num)<<endl;
		cout<<"Please input the number:"<<endl;
	}
	return 0;
}
