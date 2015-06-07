#/usr/bin/env python

import pdb

class Solution:
    # @param {integer[][]} matrix
    # @return {void}
    def setZeroes(self , matrix):
        row = []
        col = []
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if matrix[i][j] == 0:
                    row.append(i)
                    col.append(j)
        #pdb.set_trace()        
        for i in range(len(row)):
            for j in range(len(matrix[0])):
                matrix[row[i]][j] = 0
            for j in range(len(matrix)):
                matrix[j][col[i]] = 0
        return None

matrix = [[0] , [1]]
sol = Solution()
sol.setZeroes(matrix)
for i in range(len(matrix)):
    print matrix[i]
