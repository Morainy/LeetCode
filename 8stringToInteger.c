/*
 * =====================================================================================
 *
 *       Filename:  8stringToInteger.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015年04月26日 16时17分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

int myAtoi(char* str) {        
    char* p = str;
    while (*p != '\0' && *p == ' ') ++p;

    int sign = 1;
    if (*p == '-') {
        ++p;
        sign = -1;
    } else if (*p == '+') {
        ++p;
    }

    int res = 0;
    while (*p != '\0') {
        if (*p < '0' || *p > '9') break;

        int d = *p - '0';
        // check overflow
        if (res > (INT_MAX-d)/10) return sign > 0 ? INT_MAX : INT_MIN;

        res = res*10 + d;
        ++p;
    }
    return sign*res;

}

