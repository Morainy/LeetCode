/*
 * =====================================================================================
 *
 *       Filename:  29divide.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月14日 20时53分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

#define MAX_INT (0x1<<31 -1)
class Solution{
	public:
		int divide(int dividend , int divisor);
		int add(int a , int b);
		int negative(int a)
		{
			return add(~a , 1);
		}
		int sub(int a , int b);
		int pos_multiply(int a ,int b);
};

int Solution::pos_multiply(int a , int b)
{
	int ans = 0;
	while(b){
		if(b & 1){
			ans = add(ans , a);
		}
		a = (a<<1);
		b = (b>>1);
	}
	return ans;
}
int Solution::add(int a ,int b)
{
	int ans;
	while(b){
		ans = a^b;			//不带进位加法
		b = ((a&b)<<1);		//进位
		a = ans;
	}
}

int Solution::sub(int a , int b)
{
	return (a , negative(b));
}

int Solution::divide(int a , int b)
{
	if(b ==0){
		return 2147483647;
	}
	if(a == 0){
		return 0;
	}
	if(a == -2147483648 && b==1){
		return -2147483648;
	}
	int sign;
	unsigned anum = a , bnum = b;
	sign = (a>0)^(b>0);
	if(a<0){
		anum =-a;
	}
	if(b<0){
		bnum = -b;
	}
	int ans = 0;
	unsigned ansTmp = 0;
	for(int i = 31 ; i >= 0 ;i--){
		if((anum>>i)>=bnum){
			if((ansTmp + (1<<i)) > 2147483647){
				return 2147483647;
			}
			ansTmp += 1<<i;
			anum -=(bnum<<i);
		}
	}
	if(sign){
		ans = -ansTmp;
	}
	else{
		ans = ansTmp;
	}
	return ans;
}

int main(int argc , char * argv[])
{
	int num1 = -2147483648 , num2 = 1;
	Solution sol;
	int res = sol.divide(num1 , num2);
	cout<<"res = "<<res<<endl;
}

