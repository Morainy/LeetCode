#/usr/bin/env python

class Solution:
    # @param {string} path
    # @return {string}
    def simplifyPath(self , path):
        res = []
        splistRes = path.split('/')
        for i in range(len(splistRes)):
            if splistRes[i] != '':
                if splistRes[i] == '.':
                    continue
                if splistRes[i] == '..':
                    if len(res) > 0:
                        res.pop()
                    else:
                        continue
                else:
                    res.append(splistRes[i])
        resStr = ''
        if len(res) < 1:
            resStr += '/'
        else:
            for i in range(len(res)):
                resStr += '/'+res[i]
        return resStr

#str = raw_input("Please input string:\n")
#str = '/a/./b/../../c/'
#str = "/../"
str = '/home//foo/'
sol = Solution()
res = sol.simplifyPath(str)
print 'res =' , res
