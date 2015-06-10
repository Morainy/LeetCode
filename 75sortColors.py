#/usr/bin/env python

class Solution:
    # @param {integer[]} nums
    # @return {void}
    def sortColors(self , nums):
        nums.sort()

nums =[1 , 1 , 1 , 2 ,1 , 2 , 1, 0]
sol = Solution()
sol.sortColors(nums)
print nums
