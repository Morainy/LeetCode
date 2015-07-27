/*
 * =====================================================================================
 *
 *       Filename:  123maxProfit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月26日 09时50分51秒
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
using namespace std;

class Solution{
	public:
		int maxProfit(vector<int>& prices);
		int solve(int k , vector<int>& prices);
};

int Solution::solve(int k , vector<int>& prices)
{
	int days = prices.size();
	int tradeCount = 0 , profitCount = 0 , rangeProfitCount = 0;
	for(int i = 1 ; i < days ; i++){
		if(prices[i-1] < prices[i]){
			rangeProfitCount += prices[i]-prices[i-1];
			if(i == days-1){
				profitCount += rangeProfitCount;
				tradeCount += 1;
			}
		}else if(rangeProfitCount > 0){
			profitCount += rangeProfitCount;
			tradeCount += 1;
			rangeProfitCount = 0;
		}
	}
	if(tradeCount <= k){
		return profitCount;
	}
	vector<vector<int> > global(k+1 , vector<int>(days , 0));
	vector<vector<int> > local(k+1 , vector<int>(days , 0));

	for(int i = 1 ; i <= k ; i++){
		for(int j = 1 ; j < days ; j++){
			int diff = prices[j] - prices[j-1];
			local[i][j] = global[i-1][j-1] > local[i][j-1]+diff?global[i-1][j-1]:local[i][j-1]+diff;
			global[i][j] = global[i][j-1] > local[i][j]?global[i][j-1]:local[i][j];
		}
	}
	return global[global.size() -1][global[0].size() -1];
}

int Solution::maxProfit(vector<int>& prices)
{
	return solve(2 , prices);
}

int main(int argc , char* argv[])
{

}
