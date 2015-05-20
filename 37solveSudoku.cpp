/*
 * =====================================================================================
 *
 *       Filename:  37solveSudoku.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月20日 09时59分03秒
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
		void solveSudoku(vector<vector<char> >& board);
		bool isValid(vector<vector<char> >& board , int i , int j);
		bool solve(vector<vector<char> >& board , int i , int j);
};

void Solution::solveSudoku(vector<vector<char> >& board)
{
	if(board.size() != 9 || board[0].size() != 9){
		return;
	}else{
		solve(board , 0 , 0);
	}
}

bool Solution::solve(vector<vector<char> >& board , int i , int j)
{
	if(j >=9){
		return solve(board , i+1 , 0);
	}
	if(i >=9){
		return true;
	}
	if(board[i][j] == '.'){
		for(int k = 0 ; k < 9 ;k++){
			board[i][j] = k+'1';
			if(isValid(board , i , j)){
				if(solve(board , i , j+1)){
					return true;
				}
			}
			board[i][j] = '.';
		}
	}else{
		return solve(board , i , j+1);
	}
	return false;
}
bool Solution::isValid(vector<vector<char> >& board , int i , int j)
{
	for(int k = 0 ; k < 9 ; k++){
		if(k == j){
			continue;
		}else{
			if(board[i][k] == board[i][j]){
				return false;
			}
		}
	}
	for(int k = 0 ; k < 9 ;k++){
		if(k == i){
			continue;
		}else{
			if(board[k][j] == board[i][j]){
				return false;
			}
		}
	}

	for(int m = i/3*3 ; m < i/3*3+3 ; m++){
		for(int n = j/3*3 ; n < j/3*3+3 ; n++){
			if(m == i && n == j){
				continue;
			}else{
				if(board[m][n] == board[i][j]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(int argc , char * argv[])
{
	vector<vector<char> > v;
	v.resize(9);
	for(int i = 0 ; i < 9 ;i++){
		v[i].resize(9);
	}
	for(int i = 0 ; i < 9 ;i++){
		for(int j = 0 ; j < 9; j++){
			v[i][j] = '.';
		}
	}



	Solution sol;
	sol.solveSudoku(v);

	for(int i = 0 ; i < 9 ;i++){
		for(int j = 0 ; j < 9 ;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
