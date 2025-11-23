class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum % 2) return false;

        int target = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        

        for (int k = 0; k <= target; k++) {
            if (nums[0] == k) {
                dp[0][k] = 1;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int k = 0; k <= target; ++k) {
                bool take = 0;
                if (nums[i] <= k)
                    take = dp[i - 1][k - nums[i]];
                bool notTake = dp[i - 1][k];

                dp[i][k] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};