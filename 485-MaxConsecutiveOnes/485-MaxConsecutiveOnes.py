# Last updated: 06/07/2026, 11:59:10
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        return len(max("".join(map(str,nums)).split("0")))
        