class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        startIndex = -1
        maxLen = 0

        for i in range(0, len(s)):
            low = i
            high = i

            while(low >= 0 and high < len(s)):
                if s[low] == s[high]:
                    if maxLen < high-low+1:
                        startIndex = low
                        maxLen = high-low+1
                    low -= 1
                    high += 1
                else:
                    break
        
        for i in range(0, len(s)-1):
            low = i
            high = i+1

            while(low >= 0 and high < len(s)):
                if s[low] == s[high]:
                    if maxLen < high-low+1:
                        startIndex = low
                        maxLen = high-low+1
                    low = low - 1
                    high = high + 1
                else:
                    break
        return s[startIndex:startIndex+maxLen]