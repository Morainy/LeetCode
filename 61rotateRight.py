#/usr/bin/env python

import pdb

class ListNode:
    def __init__(self , x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @param {ListNode}
    def rotateRight(self , head , k):
        if not head or not head.next:
            return head
        p = head
        count = 0
        while p:
            p = p.next
            count += 1
        k %= count
        p1 = head
        p2 = head
        cnt = 1
        while p2.next:
            if cnt > k:
                p1 = p1.next
            cnt += 1
            p2 = p2.next
        #pdb.set_trace()
        p2.next = head
        res = p1.next 
        p1.next = None
        return res

l1 = ListNode(1)
l2 = ListNode(2)
#l3 = ListNode(3)
#l4 = ListNode(4)
#l5 = ListNode(5)

l1.next = l2
#l2.next = l3
#l3.next = l4
#l4.next = l5

sol = Solution()
res = sol.rotateRight(l1 , 2)
p1 = res
while p1:
    print p1.val , "->",
    p1 = p1.next
