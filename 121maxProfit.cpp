/*
 * =====================================================================================
 *
 *       Filename:  121maxProfit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月25日 20时12分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
	public:
		int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices)
{
	if(prices.size() < 1){
		return 0;
	}
	stack<int> min;
	min.push(prices[0]);
	int res = 0;
	for(int i = 1 ; i < prices.size() ; i++){
		if(prices[i] > min.top()){
			min.push(min.top());
			if(prices[i] - min.top() > res){
				res = prices[i]-min.top();
			}
		}else{
			min.push(prices[i]);
		}
	}
	return res;
}

int main(int argc , char* argv[])
{
	int a[] = {2 , 1};
	int size = sizeof(a)/sizeof(a[0]);
	vector<int> v(a , a+size);
	Solution sol;
	cout<<"res = "<<sol.maxProfit(v)<<endl;
}

