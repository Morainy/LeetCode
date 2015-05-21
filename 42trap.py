#/usr/bin/env python
'''
class Solution:
    # @param {integer[]}height
    # @return {integer}
    def trap(self , height):
        leftMax = 0
        rightMax = 0
        res = 0
        for i in range(len(height)):
            if i > 0 and i < len(height)-1:
                left = i - 1
                right =i + 1
                while left >= 0:
                    if leftMax < height[left]:
                        leftMax = height[left]
                    left -= 1
                while right < len(height):
                    if rightMax < height[right]:
                        rightMax = height[right]
                    right += 1
                if leftMax <= rightMax:
                    res += leftMax - height[i]
                else:
                    res += rightMax - height[i]
        return res
'''
import pdb

class Solution:
    # @param {integer[]}height
    # @return {integer}
    def trap(self , height):
        list = []
        leftMax = 0
        for i in range(len(height)):
            list.append(leftMax)
            if leftMax < height[i]:
                leftMax = height[i]
        #pdb.set_trace()
        rightMax = 0
        res = 0
        for i in range(len(height)-1 , -1 , -1):
            if list[i] <= rightMax:
                if list[i]>height[i]:
                    res += list[i] - height[i]
            else:
                if rightMax > height[i]:
                    res += rightMax - height[i]
            if rightMax < height[i]:
                rightMax = height[i]
        return res

height =[0,1,0,2,1,0,1,3,2,1,2,1]
sol = Solution()
res = sol.trap(height)
print "res=",res
