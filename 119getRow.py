#!/usr/bin/env python

class Solution:
    # @param {integer} rowIndex
    # @return {ionteger[]}
    def getRow(self , rowIndex):
        res = [0]*(rowIndex+1)
        for i in range(rowIndex+1):
            if i > rowIndex/2:
                res[i] = res[rowIndex-i]
            else:
                res[i] = self.combination(i , rowIndex)
        return res
    def fact(self , s , e):
        res = 1
        if s == 0:
            return res
        for i in range(s , e+1):
            res *= i
        return res
    def combination(self , m , n):
        res = 1
        res = self.fact(n-m+1 , n)/self.fact(1 , m)
        return res

sol = Solution()
res = sol.getRow(18)
print "res = " , res
print "fact(1 , 3) = ", sol.fact(1 , 3)
print "combination(1 , 3) = " , sol.combination(1 , 3)
