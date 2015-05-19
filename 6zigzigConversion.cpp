/*
 * =====================================================================================
 *
 *       Filename:  6zigzigConversion.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月23日 23时08分55秒
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
		string convert(string s , int numRows);
};

string Solution::convert(string s , int numRows)
{
	int length = s.length();
	if(length <= 1 || numRows <= 1){
		return s;
	}
	int circle = 2*numRows - 2;
	int count = length / circle;
	int mod = length % circle;
	string res;
	int distance = 2*numRows -2;	
	int i , j;
	for(i = 0 ; i < numRows ; i++){
		for(j = 0 ; j <count ; j++){
			//res.append(1 , s.at(i + j));
			res.append(1 , s.at(i + j*distance));
			if(i != 0 && i != numRows-1){
				res.append(1 , s.at(i + j * distance + circle));
			}
		}
		if(i < mod){
			res.append(1 , s.at(i + j*distance));
			if( i >= 2*numRows - mod - 1 && i!= numRows -1){
				res.append(1 , s.at(i + j*distance + circle));
			}
		}
		circle -= 2;
	}
	return res;
}

int main(int argc ,char * argv[])
{
	string str("ABCDE");
	Solution sol;
	string res = sol.convert(str , 4);
	cout<<"res = " << res<<endl;
}
