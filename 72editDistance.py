#/usr/bin/env python
class Solution:
    # @param {string} word1
    # @param {string} word2
    # @param {integer}
    def minDistance(self , word1 , word2):
        res = 0
        m = len(word1)
        n = len(word2)
        if m < 1:
            return n
        if n < 1:
            return m
        matrix = []
        for i in range(m+1):
            tmp = []
            for j in range(n+1):
                tmp.append(0)
            matrix.append(tmp)
        for i in range(m+1):
            matrix[i][0] = i 
        for i in range(n+1):
            matrix[0][i] = i
        for i in range(1 , m+1):
            for j in range(1 , n+1):
                if word1[i-1] == word2[j-1]:
                    matrix[i][j] = matrix[i-1][j-1]
                else:
                    matrix[i][j] = Solution.min(self , matrix[i-1][j-1] , matrix[i][j-1] , matrix[i-1][j])+1
        return matrix[m][n]
    
    def min(self , a , b , c):
        min = a
        if min > b:
            min = b
        if min > c:
            min = c
        return min

sol = Solution()
word1 = "ab"
word2 = "a"
res = sol.minDistance(word1 , word2)
print "res = ", res
