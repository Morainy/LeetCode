class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self , n):
        num1 = self.fact(2*n , n + 1)/self.fact(n)
        num2 = self.fact(2*n , n + 2)/self.fact(n - 1)
        return num1 - num2
    def fact(self , end , start = 1):
        res = 1
        for i in range(start , end+1):
            res *= i
        return res

sol = Solution()
res = sol.numTrees(19)
print "res = " , res
