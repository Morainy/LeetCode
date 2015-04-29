/*
 * =====================================================================================
 *
 *       Filename:  13romanToInteger.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月29日 15时00分30秒
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
		int romanToInt(string s);
};

int Solution::romanToInt(string s)
{
	int res = 0;
	int pos  = 0;
	int len = s.length();
	while(pos < len){
		if(s.at(pos) == 'M'){
			res = res + 1000;
			pos++;
			continue;
		}
		else if(s.at(pos) == 'C'){
			if(pos +1 <len &&  s.at(pos +1) == 'D'){
				res = res + 400;
				pos += 2;
				continue;
			}
			else if(pos + 1 < len && s.at(pos+1) == 'M'){
				res = res + 900;
				pos += 2;
				continue;
			}
			else{
				res = res + 100;
				pos++;
				continue;
			}
		}
		else if(s.at(pos) == 'D'){
			res = res + 500;
			pos++;
			continue;
		}
		else if(s.at(pos) == 'X'){
			if(pos + 1 <len && s.at(pos + 1) == 'L'){
				res = res + 40;
				pos += 2;
				continue;
			}
			else if(pos +1<len && s.at(pos+1) == 'C'){
				res = res + 90;
				pos += 2;
				continue;
			}
			else{
				res = res + 10;
				pos++;
				continue;
			}
		}
		else if(s.at(pos) == 'L'){
			res = res + 50;
			pos++;
			continue;
		}
		else if(s.at(pos) == 'I'){
			if(pos+1 < len && s.at(pos+1)=='V'){
				res = res + 4;
				pos += 2;
				continue;
			}
			if(pos + 1<len && s.at(pos+1)=='X'){
				res = res + 9;
				pos += 2;
				continue;
			}
			else{
				res = res +1;
				pos++;
				continue;
			}
		}
		else if(s.at(pos) == 'V'){
			res = res + 5;
			pos++;
		}
	}
	return res;
}

int main(int argc,char * argv[])
{
	Solution sol;
	string str;
	while(cin>>str){
		cout<<sol.romanToInt(str)<<endl;
	}
	return 0;
}
