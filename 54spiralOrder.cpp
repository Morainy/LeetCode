/*
 * =====================================================================================
 *
 *       Filename:  54spiralOrder.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月27日 20时26分45秒
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
		vector<int> spiralOrder(vector<vector<int> >& matrix);
};

vector<int> Solution::spiralOrder(vector<vector<int> >& matrix)
{
	vector<int> res;
	if(matrix.size() < 1 || matrix[0].size() < 1){
		return res;
	}
	vector<vector<int> > map;
	//map.resize(matrix.size());
	for(int i = 0 ; i < matrix.size()+2 ; i++){
		vector<int> tmp(matrix[0].size()+2 , 0);
		map.push_back(tmp);
	}
	for(int i = 0 ; i < map[0].size() ; i++){
		map[0][i] = 1;
		map[map.size() -1][i] = 1;
	}
	for(int i = 0 ; i < map.size() ; i++){
		map[i][0] = 1;
		map[i][map[0].size()-1] = 1;
	}
	const int right = 0 , down = 1 , left = 2 , up = 3;
	int direction = right;
	int row = 0 , column = 0;
	while(map[row+1][column+1]==0 || map[row+2][column+1]==0 || map[row][column+1]==0 || map[row+1][column]==0 || map[row+1][column+2]==0){
		switch(direction % 4){
			case right:
				if(row != 0 || column != 0){
					column++;
				}
				while(column < matrix[row].size() && map[row+1][column+1] == 0){
					res.push_back(matrix[row][column]);
					map[row+1][column+1] = 1;
					column++;
				}
				column--;
				direction++;
				break;
			case down:
				row++;
				while(row < matrix.size() && map[row+1][column+1] == 0){
					res.push_back(matrix[row][column]);
					map[row+1][column+1] = 1;
					row++;
				}
				row--;
				direction++;
				break;
			case left:
				column--;
				while(column >= 0 && map[row+1][column+1] == 0){
					res.push_back(matrix[row][column]);
					map[row+1][column+1] = 1;
					column--;
				}
				column++;
				direction++;
				break;
			case up:
				row--;
				while(row >= 0 && map[row+1][column+1] == 0){
					res.push_back(matrix[row][column]);
					map[row+1][column+1] = 1;
					row--;
				}
				row++;
				direction++;
				break;
		}
	}
	return res;
}

int main(int argc , char * argv[])
{
	vector<vector<int> > matrix;
	vector<int> v1;
	/*vector<int> v2;
	vector<int> v3;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	
	matrix.push_back(v1);
	matrix.push_back(v2);*/
	v1.push_back(2);
	v1.push_back(3);
	matrix.push_back(v1);
	vector<int> res;
	Solution sol;
	res = sol.spiralOrder(matrix);
	for(int i = 0 ; i < res.size() ; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}

