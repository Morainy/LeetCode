#/usr/bin/env python
import pdb 

class Solution:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self , a , b):
        m = len(a)
        n = len(b)
        one = '0'
        i = m - 1
        j = n - 1
        res = ""
        while i >= 0 and j >= 0:
            tmp = Solution.addBit(self , a[i] , b[j] , one)
            #pdb.set_trace()
            if tmp == 3:
                res = '1' + res
                one = '1'
            elif tmp == 2:
                res = '0' + res
                one = '1'
            elif tmp == 1:
                res = '1' + res
                one = '0'
            else:
                res = '0' + res
                one = '0'
            i -= 1
            j -= 1
        while i >= 0:
            tmp = Solution.addBit(self , a[i] , '0' , one)
            if tmp == 2:
                res = '0' + res
                one = '1'
            elif tmp == 1:
                res = '1' + res
                one = '0'
            else:
                res = '0' + res
                one = '0'
            i -= 1
        while j >= 0:
            tmp = Solution.addBit(self , b[j] , '0' , one)
            if tmp == 2:
                res = '0' + res
                one = '1'
            elif tmp == 1:
                res = '1' + res
                one = '0'
            else:
                res = '0' + res
                one = '0'
            j -= 1
        if one != '0':
            res = '1' + res
        return res
        
    def addBit(self , a , b , c):
        return int(a)+int(b)+int(c)

a = "0"
b = "0"
sol = Solution()
res = sol.addBinary(a , b)
print "res = " , res
