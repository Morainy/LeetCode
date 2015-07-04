class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self , n):
        num1 = self.fact2(n+1 , 2*n)/self.fact1(n)
        num2 = self.fact2(n+2 , 2*n)/self.fact1(n - 1)
        return num1 - num2
    def fact1(self ,  n):
        res = 1
        for i in range(1 ,n+1):
            res *= i
        return res
    def fact2(self , start , end):
        res = 1
        for i in range(start , end+1):
            res *= i
        return res

sol = Solution()
res = sol.numTrees(19)
print "res = " , res
