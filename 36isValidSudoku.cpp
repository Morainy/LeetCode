/*
 * =====================================================================================
 *
 *       Filename:  36isValidSudoku.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月20日 08时37分16秒
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
		bool isValidSudoku(vector<vector<char> >& board);
};

bool Solution::isValidSudoku(vector<vector<char> >& board)
{
	vector<vector<bool> >row(9 , vector<bool>(9 , false));
	vector<vector<bool> >column(9 , vector<bool>(9 , false));
	vector<vector<bool> >block(9 , vector<bool>(9 , false));

	for(int i = 0 ; i < 9 ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(board[i][j] != '.'){
				int ch = board[i][j] - '1';
				if(row[i][ch] || column[j][ch] || block[i/3*3+j/3][ch]){
					return false;
				}
				else{
					row[i][ch] = true;
					column[j][ch] = true;
					block[i/3*3+j/3][ch] = true;
				}
			}
		}
	}
	return true;
}
int main(int argc ,char * argv[])
{

}

