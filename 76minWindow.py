#!/usr/bin/env python

import pdb

class Solution:
    # @param {string} s
    # @param {string} t
    # @return {string}
    def minWindow(self , s , t):
        if len(s) == 0 and len(t)==0:
            return ""
        count1 = [0]*256
        count2 = [0]*256

        for i in range(len(t)):
            count1[ord(t[i])] += 1
            count2[ord(t[i])] += 1
        
        count = len(t)
        

        start = 0
        minSize = 1<<32
        minStart = 0
        for end in range(len(s)):
            if count2[ord(s[end])] > 0:
                count1[ord(s[end])] -= 1
                if count1[ord(s[end])] >= 0:
                    count -= 1
            if count == 0:
                while True:
                    if count2[ord(s[start])] > 0:
                        if count1[ord(s[start])] < 0:
                            count1[ord(s[start])] += 1
                        else:
                            break
                    start += 1
                #pdb.set_trace()
                if minSize > end - start + 1:
                    minSize = end-start+1
                    minStart = start
        #pdb.set_trace()
        if minSize == 1<<32:
            return ""
        return s[minStart:minStart+minSize]


s = "ADOBECODEBANC"
t = "ABC"
sol = Solution()
res = sol.minWindow(s , t)
print "res =" , res
