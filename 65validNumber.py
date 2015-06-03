#/usr/bin/env python

import pdb
import re

class Solution:
    # @param {string} s
    # @return {boolean}
    def isNumber(self , s):
        s = s.strip()
        try:
            res = float(s)
            return True
        except:
            return False
sol = Solution()
s = "3. "
print str(sol.isNumber(s))
