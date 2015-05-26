#/usr/bin/env python

class Solution:
    # @param {float} x
    # @param {integer} n
    # @return {float}
    def myPow(self , x , n):
        return x**n

x = float(raw_input("Please input the x:\n"))
n = int(raw_input("Please input the n:\n"))
sol = Solution()

print sol.myPow(x , n)
