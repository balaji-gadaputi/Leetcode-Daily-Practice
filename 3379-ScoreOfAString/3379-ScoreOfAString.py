# Last updated: 06/07/2026, 11:58:46
class Solution:
    def scoreOfString(self, s):
        sarr = []
        for i in s:
            sarr.append(i)
        x = len(sarr)
        sum = 0
        for i in range(0, x):
            if i == (x - 1):
                break
            else:
                sum = sum + abs(ord(sarr[i]) - ord(sarr[i + 1]))
        return sum
