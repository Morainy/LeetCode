/*
 * =====================================================================================
 *
 *       Filename:  32longestValidParentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月19日 09时25分47秒
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
#include <stack>
using namespace std;

class Solution{
	public:
		int longestValidParentheses(string s);
};

int Solution::longestValidParentheses(string s)
{
	stack<char> stack;
	int res = 0;
	bool flag = true;		//判断是否连续
	int length = 0;
	for(int i = 0 ; i < s.length() ; i++){
		if(!stack.empty() && s.at(i) == ')'){
			if(stack.top() == '('){
				if(flag == true){
					length += 2;
				}
				if(length > res){
					res = length;
				}
				stack.pop();
				flag = true;
			}else{
				stack.push(s.at(i));
				flag = false;
				length = 0;
			}
		}else{
			stack.push(s.at(i));
			if(flag == true){
				length = 0;
				flag = false;
			}
		}
	}
	return res;
}

int main(int argc ,char * argv[])
{
	Solution sol;
	string str("()(()");
	int res = sol.longestValidParentheses(str);
	cout<<"res="<<res<<endl;
}

