/*************************************************************************
    > File Name: FactorialTrailingZeroes.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com 
    > Created Time: 2015年03月07日 星期六 09时13分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution{
	public:
		int trailingZeroes(int n);
};
int Solution::trailingZeroes(int n)
{
	int count5 = 0;
	int i;
	int count5Temp;
	int num;
	for(i = 1 ; i <= n ; )
	{
		if(i % 5 == 0)
		{
			count5Temp = 0;
			num = i;
			while(num %5 == 0)
			{
				count5Temp++;
				num = num/5;
			}
			count5 += count5Temp;
			i += 5;
		}
		else
			i++;
	}
	return count5;
}
int main(int argc ,char * argv[])
{
	Solution sol;
	int N;
	while(cin>>N)
		cout<<sol.trailingZeroes(N)<<endl;
	return 0;
}
