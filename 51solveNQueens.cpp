/*
 * =====================================================================================
 *
 *       Filename:  51solveNQueens.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月25日 16时36分51秒
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
using namespace std;

class Solution{
	public:
		vector<vector<string> > solveNQueens(int n);
		bool isValid(vector<string>& v, int i , int j , int n);
		void solve(vector<vector<string> >& res , vector<string>& v , int i , int n);
};

void Solution::solve(vector<vector<string> >& res ,vector<string>& v , int i , int n)
{
	if(i == n){
		res.push_back(v);
		return;
	}
	for(int j = 0 ; j < n ; j++){
		if(isValid(v , i , j , n)){
			v[i][j] = 'Q';
			solve(res , v , i+1 , n);
			v[i][j] = '.';
		}
	}
}

bool Solution::isValid(vector<string>& v , int i , int j , int n)
{	
	for(int p = 0 ; p < i ; p++){
		if(v[p].at(j) == 'Q'){
			return false;
		}
	}
	int num1 = i-1 , num2 = j-1;
	while(num1 >=0 && num2 >= 0){
		if(v[num1].at(num2) == 'Q'){
			return false;
		}
		num1--;
		num2--;
	}
	
	int num3 = i-1 , num4 = j+1;
	while(num3 >= 0 && num4 < n){
		if(v[num3].at(num4) == 'Q'){
			return false;
		}
		num3--;
		num4++;
	}

	return true;
}
vector<vector<string> > Solution::solveNQueens(int n)
{
	vector<vector<string> > res;
	vector<string> vTmp;
	vTmp.resize(n);
	string tmp(n , '.');
	for(int i = 0 ; i < n ; i++){
		vTmp[i] = tmp;
	}
	solve(res , vTmp , 0 , n);	
	return res;
}

int main(int argc , char * argv[])
{
	Solution sol;
	int n = 10;
	vector<vector<string> > res = sol.solveNQueens(n);
	for(int k = 0 ; k < res.size() ; k++){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++){
				cout<<res[k][i].at(j)<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}

	cout<< "res.size() = " <<res.size()<<endl;
}
