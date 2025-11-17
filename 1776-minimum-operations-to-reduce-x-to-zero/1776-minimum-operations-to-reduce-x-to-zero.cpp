class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;

        if (target < 0) return -1;
        if (target == 0) return n;

        int left = 0, add = 0, len = -1;

        for (int right = 0; right < n; ++right) {
            add += nums[right];
            while (add > target) {
                add -= nums[left];
                left++;
            }
            if (add == target) len = max(len, right - left + 1);
        }
        return len == -1 ? -1 : n - len;
    }
};
