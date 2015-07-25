/*
 * =====================================================================================
 *
 *       Filename:  120minimumTotal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年07月23日 15时58分37秒
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

/*class Solution{
	public:
		int minimumTotal(vector<vector<int> >& triangle);
};

int Solution::minimumTotal(vector<vector<int> >& triangle)
{
	if(triangle.size() < 1){
		return 0;
	}
	vector<int> res;
	int size = triangle.size();
	res.push_back(triangle[0][0]);
	res.resize(size);
	for(int i = 0 ; i < triangle.size() ; i++){
		for(int j = 0 ; j < triangle[i].size() ; j++){
			int tmp1 = res[j];
			int tmp2 = 0x7FFFFFFF;
			if(j + 1 < triangle[i].size()){
				tmp2 = res[j+1];
			}
			int min = tmp1<tmp2?tmp1:tmp2;
			res[j] = min + triangle[i][j];
		}
	}
	int finalRes = res[0];
	for(int i = 0 ; i < res.size() ; i++){
		if(res[i] > finalRes){
			finalRes = res[i];
		}
	}
	return finalRes;
}*/

class Solution{
	public:
		int minimumTotal(vector<vector<int> >& triangle);
};

int Solution::minimumTotal(vector<vector<int> >& triangle)
{
	int sizeRow = triangle.size();
	if(sizeRow < 1){
		return 0;
	}
	int i , j;
	for(i = 1 ; i <sizeRow ; i++){
		int len = triangle[i].size();
		for(j = 0 ; j < len ; j++){
			if(j == 0){
				triangle[i][j] = triangle[i][j] + triangle[i-1][j];
			}
			else if(j == len-1){
				triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
			}
			else{
				int tmp1 = triangle[i][j] + triangle[i-1][j-1];
				int tmp2 = triangle[i][j] + triangle[i-1][j];
				triangle[i][j] = tmp1<tmp2?tmp1:tmp2;
			}
		}
	}
	int res = triangle[sizeRow-1][0];
	for(i = 1 ; i < triangle[sizeRow-1].size(); i++){
		res = triangle[sizeRow-1][i] < res?triangle[sizeRow-1][i]:res;
	}
	return res;
}

int main(int argc , char* argv[])
{
	vector<vector<int> > test;
	vector<int> tmp1;
	tmp1.push_back(2);
	vector<int> tmp2;
	tmp2.push_back(3);
	tmp2.push_back(4);
	vector<int> tmp3;
	vector<int> tmp4;
	tmp3.push_back(6);
	tmp3.push_back(5);
	tmp3.push_back(7);
	tmp4.push_back(4);
	tmp4.push_back(1);
	tmp4.push_back(8);
	tmp4.push_back(3);

	test.push_back(tmp1);
	test.push_back(tmp2);
	test.push_back(tmp3);
	test.push_back(tmp4);

	Solution sol;
	cout<<"res = "<<sol.minimumTotal(test)<<endl;
}

