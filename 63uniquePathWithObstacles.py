#/usr/bin/env python

import pdb

class Solution:
    # @param{integer[][]} obstacleGrid
    # @return {integer}
    def uniquePathsWithObstacles(self , obstacleGrid):
        m = len(obstacleGrid)
        if m < 1:
            return 0
        n = len(obstacleGrid[0])
        if n < 1:
            return 0
        res = obstacleGrid
        if obstacleGrid[0][0]:
            return 0
        res[0][0] = 1
        # pdb.set_trace()
        for j in range(1 , n):
            if obstacleGrid[0][j]:
                res[0][j] = 0
            else:
                res[0][j] = res[0][j-1]
        for i in range(1 , m):
            if obstacleGrid[i][0]:
                res[i][0] = 0
            else:
                res[i][0] = res[i-1][0]
        for i in range(1 , m):
            for j in range(1 , n):
                if obstacleGrid[i][j]:
                    res[i][j] = 0
                else:
                    res[i][j] = res[i-1][j]+res[i][j-1]
        return res[m-1][n-1]


sol = Solution()
grid = [[0 , 0 , 0],[0 , 1 , 0] , [0 , 0 ,0]]
res = sol.uniquePathsWithObstacles(grid)
print "res =" , res
