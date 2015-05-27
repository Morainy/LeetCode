/*
 * =====================================================================================
 *
 *       Filename:  53maxSubArray.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年05月27日 16时34分58秒
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

class Solution{
	public:
		int maxSubArray(int A[] , int n);
};
int Solution::maxSubArray(int A[] , int n)
{
      int sum=A[0];
    	int b=0;
	    for(int i=0; i<n; i++)  
	    {  
	        if(b<0) 
	            b=A[i];  
	        else  
	            b+=A[i];  
	        if(sum<b)  
	            sum=b;
	    }
	    return sum; 
}
int main(int argc , char * argv[])
{

}

