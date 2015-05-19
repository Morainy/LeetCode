// 200NumberOfIsland.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<char>> gridTemp;
	int numIslands(vector<vector<char>> &grid);
	bool BFS(unsigned r , unsigned c);
};

bool Solution::BFS(unsigned r , unsigned c)
{
	if (r < 0 || r>= gridTemp.size() || c < 0 || c >= gridTemp[0].size() || gridTemp[r][c] == '0')
	{
		return false;
	}
	gridTemp[r][c] = '0';
	BFS(r+1 , c);
	BFS(r-1 , c);
	BFS(r , c + 1);
	BFS(r , c - 1);
	return true;
}
int Solution::numIslands(vector<vector<char>> &grid)
{
	int result = 0;
	for (unsigned i = 0 ; i < grid.size() ; i++)
	{
		gridTemp.push_back(grid[i]);
	}
	for (unsigned i = 0 ; i < gridTemp.size(); i++)
	{
		for(unsigned j = 0 ; j < gridTemp[i].size() ; j++)
		{
			if(BFS(i , j))
				result++;
		}
	}
	return result;
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

