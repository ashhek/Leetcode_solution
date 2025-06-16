class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = INT_MIN;
        int minElement = nums[0];

        for(int i=1; i<nums.size(); ++i) {
            if(nums[i] > minElement)
            ans = max(ans, nums[i] - minElement);
            minElement = min(minElement, nums[i]);
        }
        return ans == INT_MIN ? -1 : ans;
    }
};