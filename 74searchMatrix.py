#/usr/bin/env python

import pdb

class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @ return {boolean}
    def searchMatrix(self , matrix , target):
        length = len(matrix)
        l = []
        for i in range(length):
            l.append(matrix[i][0])
        res = Solution.binarySearch(self , l , target)
        #pdb.set_trace()
        if res < 0:
            return True
        else:
            final = Solution.binarySearch(self , matrix[res] , target)
            if final < 0:
                return True
            else:
                return False
    def binarySearch(self , l , target):
        res = -1
        s = 0
        e = len(l) - 1
        if len(l) == 0:
            return 0
        elif len(l) == 1:
            if target == l[0]:
                return -1
            else:
                return 0
        while s <= e:
            m = (s + e)/2
            if l[m] == target:
                return -1
            elif l[m] < target:
                s = m + 1
            else:
                e = m - 1
        if s >= len(l):
            return len(l)-1
        if target < l[s]:
            if s == 0:
                return 0
            else:
                return s-1
        else:
            return s

sol = Solution()
#matrix = [[1 , 3 , 5 , 7] , [10 , 11 , 16 , 20] , [23 , 30 , 34 , 50]]
matrix = [[1 , 1]]
res = sol.searchMatrix(matrix , 2)
print "res = " , res
