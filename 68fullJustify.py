#/usr/bin/env python

import pdb

class Solution:
    # @param {string[]} words
    # @param {integer[]} maxWidth
    # @return {string[]}
    def fullJustify(self , words , maxWidth):
        if len(words) < 1 or maxWidth < 1:
            return []
        if len(words) <= maxWidth:
            return words
        res = []
        strs = []
        sum = 0
        #countSpace = 0
        for i in range(len(words)):
            if len(words[i]) == maxWidth:
                res.append(words[i])
                continue

            #pdb.set_trace()

            sum += len(words[i])
            #countSpace += 1
            if sum > maxWidth:
                sumTmp = sum - len(words[i])
                spaceNum = maxWidth - sumTmp
                wordsNum = len(strs)
                evenSpace = spaceNum /(wordsNum-1)
                modEvenSpace = spaceNum % (wordsNum-1)
                str = ""
                for j in range(len(strs)-1):
                    str += strs[j]
                    if modEvenSpace:
                       tmp = evenSpace + 1
                    else:
                        tmp = evenSpace
                    while tmp > 0:
                        str += ' '
                        tmp -= 1
                    modEvenSpace -= 1
                #pdb.set_trace()
                str += strs[-1]
                res.append(str)
                sum = 0
                strs = []
                countSpace = 0
                
                sum += len(words[i])
                strs.append(words[i])
            else:
                strs.append(words[i])
        if strs:
            str = ""
            for j in range(len(strs)):
                str += strs[j]
            str.ljust(maxWidth)
            res.append(str)
        return res

sol = Solution()
#words = ["This", "is", "an", "example", "of", "text", "justification."]
#res = sol.fullJustify(words , 16)
#words = ["a" , "b" , "c" , "d" , "e"]
#res = sol.fullJustify(words , 1)
words = ["Listen" , "to" , "many" , "speak" , "to" , "a" , "few."]
res = sol.fullJustify(words , 6)
print res
