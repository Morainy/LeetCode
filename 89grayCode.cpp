/*
 * =====================================================================================
 *
 *       Filename:  89grayCode.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年06月29日 15时52分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution{
public:
	vector<int> grayCode(int n);
	int power(int a , int b);
};

int Solution::power(int a , int b)
{
	int res = 1;
	for(int i = 0 ; i < b ; i++){
		res *= a;
	}
	return res;
}
vector<int> Solution::grayCode(int n)
{
	vector<int> res;
	if(n == 0){
		res.push_back(0);
		return res;
	}
	int size = power(2 , n);
	res.resize(size);
	res[1] = 1;
	for(int i = 1 , offset = 1; i <= size/2 ; i = power(2 , offset)-1){
		for(int j = i + 1; j < 2*(i+1) ; j++){
			res[j] = res[2*(i+1) - j - 1] | (1<<offset);
		}
		offset++;
	}
	return res;
}
