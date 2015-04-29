/*
 * =====================================================================================
 *
 *       Filename:  12intergerToRoman.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月28日 23时07分37秒
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
		string intToRoman(int num);
};

string Solution::intToRoman(int num)
{
	string res;
	string digitals[] = {"" , "I" , "II" , "III" , "IV" , "V" , "VI" , "VII" , "VIII" , "IX"};
	string tens[] = {"" , "X" , "XX" , "XXX" , "XL" , "L" , "LX" , "LXX" , "LXXX" , "XC"};
	string hundreds[] = {"" , "C" , "CC" , "CCC" , "CD" , "D" , "DC" , "DCC" , "DCCC" , "CM"};
	string thousands[] = {"" , "M" , "MM" , "MMM"};

	string * trans[] = {digitals , tens , hundreds , thousands};
	int index = 0;
	while(num > 0){
		res = trans[index][num %10] + res;
		num = num/10;
		index++;
	}
	return res;
}

int main(int argc ,char * argv[])
{
	int num;
	Solution sol;
	while(cin>>num){
		cout << sol.intToRoman(num)<<endl;
	}
}

