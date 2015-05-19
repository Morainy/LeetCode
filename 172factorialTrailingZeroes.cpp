/*
 * =====================================================================================
 *
 *       Filename:  172factorialTrailingZeroes.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月20日 21时59分32秒
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
		int trailingZeroes(int n);
};

int Solution::trailingZeroes(int n)
{
	if(n <= 0){
		return 0;
	}
	int num = 0;
	while(n){
		num += n/5;
		n = n/5;
	}
	return num;
}

int main(int argc ,cahr * argv[])
{

}
