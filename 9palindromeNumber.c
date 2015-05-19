/*
 * =====================================================================================
 *
 *       Filename:  9palindromeNumber.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月26日 16时24分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(int x)
{
	char str[20] = {0};
	sprintf(str , "%d" , x);
	int len = strlen(str);
	if(len <= 1){
		return true;
	}
	int i , j;
	for(i = 0 , j = len -1 ; i <= j; i++ ,j--){
		if(str[i] != str[j]){
			return false;
		}
	}
	return true;
}
int main(int argc ,char * argv[])
{
	int x;
	printf("Please input the Number: x\n");
	scanf("%d",&x);
	bool res = isPalindrome(x);
	printf("res = %d\n" , res);
}
