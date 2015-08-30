/*
 * =====================================================================================
 *
 *       Filename:  135candy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年08月30日 19时08分55秒
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
		int candy(vector<int>& ratings);
};

int Solution::candy(vector<int>& ratings)
{
	if(ratings.size() < 1){
		return 0;
	}
	if(ratings.size() == 1){
		return 1;
	}
	vector<int> result(ratings);
	result[0] = 1;
	int i = 1;
	while(i < ratings.size()){
		if(ratings[i] > ratings[i-1]){
			result[i] = result[i-1] + 1;
			i++;
			continue;
		}else{
			int beforeIndex = i-1;
			int beforeVal = result[i-1];
			while(i < ratings.size() && ratings[i] <ratings[i-1]){
				i++;
			}
			int intval = i - beforeIndex;
			if(intval >= beforeVal){
				result[beforeIndex] = intval;
			}
			intval--;
			for(int j = beforeIndex+1 ; j < i ; j++){
				result[j] = intval;
				intval--;
			}
			if(ratings[i] == ratings[i-1]){
				result[i] = 1;
				i++;
			}
		}
	}

	int res = 0;
	for(int j = 0 ; j < result.size() ;j++){
		res += result[j];
	}
	return res;
}

int main(int argc , char* argv[])
{
	//int a[] = {1 , 5 , 4 , 3 , 2};
	int a[] = {2 , 2};
	int len = sizeof(a)/sizeof(a[0]);
	vector<int> v(a , a + len);

	Solution sol;
	int res = sol.candy(v);
	cout<<"res = "<<res<<endl;
}
