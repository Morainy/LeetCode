#/usr/bin/env python

class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def uniquePaths(self , m , n):
        p = Solution.fact(self , m+n-2)
        a1 = Solution.fact(self , m-1)
        a2 = Solution.fact(self , n-1)
        return p/(a1*a2)
    def fact(self , n):
        if n <= 1:
            return 1
        sum = 1
        for i in range(1 , n+1):
            sum *= i
        return sum

sol = Solution()
print sol.uniquePaths(3 , 7) 
