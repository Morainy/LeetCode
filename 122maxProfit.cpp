/*
 * =====================================================================================
 *
 *       Filename:  122maxProfit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月25日 20时54分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
	public:
		int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices)
{
	int res = 0;
	if(prices.size() < 1){
		return res;
	}
	for(int i = 0 ; i < prices.size()-1 ; i++){
		if(prices[i+1] > prices[i]){
			res += prices[i+1] - prices[i];
		}
	}
	return res;
}

int main(int argc , char* argv[])
{

}

