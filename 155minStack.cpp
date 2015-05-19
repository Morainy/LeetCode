/*
 * =====================================================================================
 *
 *       Filename:  155minStack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 09时38分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stack>
#include <iostream>
using namespace std;

class MinStack
{
	private:
		stack<int> dataStack;
		stack<int> MinStack;
	public:
		void push(int x);
		void pop();
		int top();
		int getMin();
};

void MinStack::push(int x)
{
	dataStack.push(x);
	if(MinStack.empty()){
		MinStack.push(x);
	}
	else {
		if(MinStack.top() < x){
			MinStack.push(MinStack.top());
		}
		else{
			MinStack.push(x);
		}
	}
}
void MinStack::pop()
{
	dataStack.pop();
	MinStack.pop();
}
int MinStack::top()
{
	return dataStack.top();
}
int MinStack::getMin()
{
	return MinStack.top();
}

int main(int argc ,char * argv[])
{

}
