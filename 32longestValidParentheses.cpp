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

/*int Solution::longestValidParentheses(string s)
{
	stack<char> stack;
	int res = 0;
	int length = 0;
	//bool flag;
	for(int i = 0 ; i < s.length() ; i++){
		if(s.at(i) == ')'){
			if(stack.empty()){
				stack.push(s.at(i));
				continue;
			}
			if(stack.top() == '('){
				length += 2;
				if(length > res){
					res = length;
				}
				stack.pop();
			}else{
				stack.push(s.at(i));
				length = 0;
			}
		}else{
			stack.push(s.at(i));
			flag = false;
			length = 0;
		}
	}
	return res;
}*/

int Solution::longestValidParentheses(string s)
{
	int res = 0;
	if(s.length() <=0){
		return res;
	}
	int start = -1;
	int length = 0;
	stack<int> stack;
	for(int i = 0 ; i < s.length() ; i++){
		if(s.at(i) == '('){
			stack.push(i);
		}else{
			if(!stack.empty()){
				stack.pop();
				if(stack.empty()){
					length = i-start;
					if(length > res){
						res = length;
					}
				}
				else{
					length = i - stack.top();
					if(length > res){
						res = length;
					}
				}
			}
			else{
				start = i;
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

