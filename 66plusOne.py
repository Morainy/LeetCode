#/usr/bin/env python
class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(slef , digits):
        length = len(digits)
        i = length -1
        res = 1
        while i >= 0:
            res += digits[i]
            if res / 10 == 0:
                digits[i] = res
                res = 0
                break
            else:
                digits[i] = res % 10
                res /= 10
                i -= 1
        if res != 0:
            digits.insert(i+1 , res)
        return digits

sol = Solution()
#l = [9 , 9 ,9 , 9 , 9 , 9 , 9]
l = [0]
l = sol.plusOne(l)
print l
