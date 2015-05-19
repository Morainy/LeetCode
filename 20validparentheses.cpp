/*
 * =====================================================================================
 *
 *       Filename:  19validparentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月07日 22时25分15秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stack>
#include <string>
using namespace std;

class Solution{
	public:
		bool isValid(string s);
};

bool Solution::isValid(string s)
{
	stack<char> stack;
	for(int i = 0 ; i < s.length() ; i++){
		char ch = s.at(i);
		if(ch == '(' || ch == '[' || ch == '{'){
			stack.push(ch);
		}
		else if(stack.empty()){
			return false;
		}
		else if(ch == ')'){
			if(stack.top() == '('){
				stack.pop();
			}
			else{
				return false;
			}
		}
		
		else if(ch == ']'){
			if(stack.top() == '['){
				stack.pop();
			}
			else{
				return false;
			}
		}

		else if(ch == '}'){
			if(stack.top() == '{'){
				stack.pop();
			}
			else{
				return false;
			}
		}
	}
	if(!stack.empty()){
		return false;
	}
	return true;
}

int main(int argc ,char * argv[])
{
	return 0;
}
