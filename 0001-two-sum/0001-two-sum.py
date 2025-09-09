class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for i in range(0, len(nums)):
            if target - nums[i] in dict:
                return [i, dict.get(target-nums[i])]
            else:
                dict[nums[i]] = i
        
        return []