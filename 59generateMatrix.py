#/usr/bin/env python
import pdb

class Solution:
    # @param {integer} n
    # @return {integer[][]}
    def generateMatrix(self , n):
        res = [None] * n
        for i in range(len(res)):
            res[i] = [0]*n
        val = 1
        count = n/2

        #pdb.set_trace()

        for i in range(count+1):
            column = n -1 -i
            row = n -1 - i
            for j in range(i , column):
                res[i][j] = val
                val += 1
            for j in range(i , row):
                res[j][column] = val
                val += 1
            for j in range(column , i , -1):
                res[row][j] = val
                val += 1
            for j in range(row , i , -1):
                res[j][i] = val
                val += 1
        if n % 2 != 0:
            res[n/2][n/2] = val
        return res
       

sol = Solution()
n = 4
res = sol.generateMatrix(n)
for i in range(len(res)):
    print res[i]

