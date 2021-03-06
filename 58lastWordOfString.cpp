/*
 * =====================================================================================
 *
 *       Filename:  58lastWordOfString.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月31日 23时40分36秒
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
#include <cstring>
using namespace std;

class Solution{
	public:
		int lengthOfLastWord(string str);
};

int Solution::lengthOfLastWord(string str)
{
	char * last , * prev = NULL;
	char * ptr = const_cast<char*>(str.c_str());
	last = strtok(ptr , " ");
	while(last != NULL){
		prev = last;
		last = strtok(NULL , " ");
	}
	if(!prev){
		return 0;
	}
	return strlen(prev);
}


int main(int argc , char * argv[])
{
	string str = "";
	Solution sol;
	cout<<"res = " << sol.lengthOfLastWord(str)<<endl;
}
