#/usr/bin/env python

class Solution:
    # @param{integer[][]} grid
    # @param{integer}
    def minPathSum(self , grid):
        res = grid
        m = len(grid)
        if m < 1:
            return 0
        n = len(grid[0])
        if n < 1:
            return 0
        sum = res[0][0]
        for j in range(1 , n):
            sum += res[0][j]
            res[0][j] = sum
        sum = res[0][0]
        for i in range(1 , m):
            sum += res[i][0]
            res[i][0] = sum
        for i in range(1 , m):
            for j in range(1 , n):
                if res[i-1][j] < res[i][j-1]:
                    res[i][j] = res[i-1][j]+res[i][j]
                else:
                    res[i][j] = res[i][j-1]+res[i][j]
        return res[m-1][n-1]

sol = Solution()
grid = [[1 , 2 , 3],[4 , 5 , 6],[7 , 8 , 9]]
res = sol.minPathSum(grid)
print "res = " , res
