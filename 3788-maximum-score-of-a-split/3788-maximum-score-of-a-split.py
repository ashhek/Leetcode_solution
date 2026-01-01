class Solution:
    def maximumScore(self, nums: List[int]) -> int:
        n = len(nums)
        pref = [0]*n
        suff = [0]*n

        pref[0] = nums[0]
        suff[n-1] = nums[n-1]
        

        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]

        for j in range(n-2, -1, -1):
            suff[j] = min(suff[j+1], nums[j+1])
        
        res = -10**18
        
        for i in range(0, n-1):
            res = max(res, (pref[i] - suff[i]))
    
        return res