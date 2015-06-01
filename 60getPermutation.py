#/usr/bin/env python

class Solution:
    # @param{integer} n
    # @param{integer} k
    # @return {string}
    def getPermutation(self , n , k):
        res = ""
        nums = []
        pcount = 1
        for i in range(n):
            nums.append(i+1)
            pcount *= (i+1)
        k -= 1
        for i in range(n):
            pcount = pcount /(n-i)
            selected = k / pcount
            res += str(nums[selected])

            for j in range(selected , n-i-1):
                nums[j] = nums[j+1]
            k %= pcount
        return res
sol = Solution()
res = sol.getPermutation(9 , 273815)
print res
