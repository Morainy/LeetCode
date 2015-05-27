/*
 * =====================================================================================
 *
 *       Filename:  52totalNQueens.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月27日 11时23分29秒
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
		int totalNQueens(int n);
		void solve(vector<string>& v , int i , int n);
		bool isValid(vector<string>& v , int i , int j , int n);
		Solution():count(0){}
	private:
		int count;
};


void Solution::solve(vector<string>& v , int i , int n)
{
	if(i == n){
		count++;		
		return;
	}
	for(int j = 0 ; j < n ; j++){
		if(isValid(v , i , j , n)){
			v[i][j] = 'Q';
			solve(v , i+1 , n);
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
int Solution::totalNQueens(int n)
{
	vector<string> vTmp;
	vTmp.resize(n);
	string tmp(n , '.');
	for(int i = 0 ; i < n ; i++){
		vTmp[i] = tmp;
	}
	solve(vTmp , 0 , n);	
	return count;
}

int main(int argc , char * argv[])
{
	Solution sol;
	int n = 9;
	int res = sol.totalNQueens(n);
	cout<<"res = "<<res<<endl;
}

