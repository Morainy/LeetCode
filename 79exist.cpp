/*
 * =====================================================================================
 *
 *       Filename:  79exist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月16日 22时33分47秒
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
		bool exist(vector<vector<char> >& board , string word);
		bool solve(vector<vector<char> >& board ,vector<vector<int> >& flag , string word , int row , int col);
};

bool Solution::solve(vector<vector<char> >& board , vector<vector<int> >& flag , string word , int row , int col)
{
	if(word.length() == 1){
		if(row > 0 && !flag[row-1][col] && word.at(0) == board[row-1][col]){
			return true;
		}
		if(col < board[0].size()-1 && !flag[row][col+1] && word.at(0) == board[row][col+1]){
			return true;
		}
		if(row < board.size() - 1 && !flag[row+1][col] && word.at(0) == board[row+1][col]){
			return true;
		}
		if(col>0 && !flag[row][col-1] && word.at(0) == board[row][col-1]){
			return true;
		}
		return false;
	}

	int len = word.length();
	string tmp = word.substr(1 , len-1);
	
	if(row > 0 && !flag[row-1][col] && word.at(0) == board[row-1][col]){
		flag[row-1][col] = 1;
		if(solve(board , flag , tmp , row-1 , col)){
			return true;
		}
		flag[row-1][col] = 0;
	}
	if(col < board[0].size()-1 && !flag[row][col+1] && word.at(0) == board[row][col+1]){
		flag[row][col+1] = 1;
		if(solve(board , flag , tmp , row , col+1)){
			return true;
		}
		flag[row][col+1] = 0;
	}
	if(row < board.size()-1 && !flag[row+1][col] && word.at(0) == board[row+1][col]){
		flag[row+1][col] = 1;
		if(solve(board , flag , tmp , row+1 , col)){
			return true;
		}
		flag[row+1][col] = 0;
	}
	if(col > 0 && !flag[row][col-1] && word.at(0) == board[row][col-1]){
		flag[row][col-1] = 1;
		if(solve(board , flag , tmp , row , col-1)){
			return true;
		}
		flag[row][col-1] = 0;
	}
	return false;
}
bool Solution::exist(vector<vector<char> >& board , string word)
{	
	if(board.size() < 1 || word.length() < 1){
		return false;
	}
	vector<vector<int> > flag;
	for(int i = 0 ; i < board.size() ; i++){
		vector<int> tmp(board[i].size() , 0);
		flag.push_back(tmp);
	}
	for(int i = 0 ; i < board.size() ; i++){
		for(int j = 0 ; j < board[i].size() ; j++){
			if(word[0] == board[i][j]){
				if(word.length() == 1){
					return true;
				}
				flag[i][j] = 1;
				string tmp = word.substr(1 , word.length()-1);
				if(solve(board , flag , tmp , i , j)){
					return true;
				}
				flag[i][j] = 0;
			}
		}
	}
	return false;
}

int main(int argc , char* argv[])
{
	/*vector<char> word1;
	word1.push_back('A');
	word1.push_back('B');
	word1.push_back('C');
	word1.push_back('E');
	
	vector<char> word2;
	word2.push_back('S');
	word2.push_back('F');
	word2.push_back('C');
	word2.push_back('S');
	
	vector<char> word3;
	word3.push_back('A');
	word3.push_back('D');
	word3.push_back('E');
	word3.push_back('E');*/

	vector<char> word1;
	word1.push_back('a');
	word1.push_back('b');

	vector<char> word2;
	word2.push_back('c');
	word2.push_back('d');

	//string word("SEE");
	string word("bdca");
	vector<vector<char> > board;
	board.push_back(word1);
	board.push_back(word2);
	//board.push_back(word3);

	Solution sol;
	cout<<sol.exist(board , word)<<endl; 
}

