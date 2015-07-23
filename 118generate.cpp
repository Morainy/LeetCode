/*
 * =====================================================================================
 *
 *       Filename:  118generate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月23日 10时56分13秒
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
		vector<vector<int> > generate(int numRows);
};

vector<vector<int> > Solution::generate(int numRows)
{
	vector<vector<int> > res;
	if(numRows < 1){
		return res;
	}
	for(int i = 0 ; i < numRows ; i++){
		vector<int> tmp;
		if(i == 0){
			tmp.push_back(1);
			res.push_back(tmp);
			continue;
		}
		if(i == 1){
			tmp.push_back(1);
			tmp.push_back(1);
			res.push_back(tmp);
			continue;
		}
		tmp.push_back(1);
		int resSize = res.size();
		for(int j = 0 ; j < res[resSize-1].size() -1 ; j++){
			tmp.push_back(res[resSize-1][j] + res[resSize-1][j+1]);
		}
		tmp.push_back(1);
		res.push_back(tmp);
	}
	return res;
}

int main(int argc , char* argv[])
{
	vector<vector<int> > res;
	Solution sol;
	res = sol.generate(5);
	for(int i = 0 ; i < res.size() ; i++){
		for(int j = 0 ; j < res[i].size() ; j++){
			cout<<res[i][j]<< " ";
		}
		cout<<endl;
	}
}
