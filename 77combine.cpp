/*
 * =====================================================================================
 *
 *       Filename:  77combine.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月11日 09时29分18秒
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
		vector<vector<int> > combine(int n , int k);
		vector<vector<int> > solve(int start , int end , int k);
};

vector<vector<int> > Solution::combine(int n , int k)
{
	vector<vector<int> > res;
	if (k < 0 || n < k){
		return res;
	}
	return solve(1 , n , k);
}

vector<vector<int> > Solution::solve(int start , int end , int k)
{
	vector<vector<int> > res;
	if(k == 1){
		for(int i = start ; i <= end ; i++){
			vector<int> tmp;
			tmp.push_back(i);
			res.push_back(tmp);
		}
		return res;
	}

	for(int i = start ; i <= start+k ; i++){
		vector<vector<int> >tmp;
		tmp = solve(i + 1, end , k-1);
		for(int j = 0 ; j < tmp.size() ; j++){
			tmp[j].insert(tmp[j].begin() , i);
			res.push_back(tmp[j]);
		}
	}
	return res;
}

int main(int argc , char * argv[])
{
	Solution sol;
	vector<vector<int> > res;
	res = sol.combine(4 , 2);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
