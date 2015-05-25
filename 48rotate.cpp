/*
 * =====================================================================================
 *
 *       Filename:  48rotate.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月25日 09时06分42秒
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
		void rotate(vector<vector<int> >& matrix);
};

void Solution::rotate(vector<vector<int> >& matrix)
{
	if(matrix.size() <= 1 && matrix[0].size() <= 1){
		return;
	}
	int size = matrix.size();
	for(int i = 0 ; i < size ; i++){
		vector<int> tmp;
		for(int j = size-1 ; j >= 0 ; j--){
			tmp.push_back(matrix[j][i]);
		}
		matrix.push_back(tmp);
	}
	matrix.erase(matrix.begin() , matrix.begin()+size);
}

int main(int argc , char * argv[])
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);

	vector<vector<int> > test;
	test.push_back(v1);
	test.push_back(v2);
	Solution sol;
	
	sol.rotate(test);

	for(int i = 0 ; i < test.size() ; i++){
		for(int j = 0 ; j < test[i].size() ; j++){
			cout<<test[i][j]<<" ";
		}
		cout<<endl;
	}
}
