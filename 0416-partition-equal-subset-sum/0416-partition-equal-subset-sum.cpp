class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1)
            return false;

        vector<vector<int>> dp(n + 2, vector<int>((sum / 2) + 2, 0));
        dp[0][0] = 1;
        for(int target=0; target<=sum/2; ++target) {
            if(nums[0] == target) {
                dp[0][target] = 1;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int target = 0; target <= sum / 2; ++target) {
                int notTake = dp[i - 1][target];
                int take = 0;
                if (nums[i] <= target)
                    take = dp[i - 1][target - nums[i]];

                dp[i][target] = take || notTake;
            }
        }
        return dp[n-1][sum/2];
    }
};