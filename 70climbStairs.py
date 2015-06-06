#/usr/bin/env python

class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self , n):
        res = [1 , 2]
        for i in range(n):
            if i >= 2:
                tmp = res[i-1]+res[i-2]
                res.append(tmp)
        return res[n-1]
n = int(raw_input("Please input n:\n"))
sol = Solution()
res = sol.climbStairs(n)
print "res = " , res

