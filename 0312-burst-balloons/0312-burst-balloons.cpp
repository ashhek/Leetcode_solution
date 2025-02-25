class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int i=n-2; i>=1; --i) {
            for(int j=1; j<=n-2; ++j) {
                if(i > j) continue;

                int maxCoins = INT_MIN;
                for(int k=i; k<=j; ++k) {
                    int coins = nums[i-1] * nums[k] * nums[j+1];
                    int subCoins = dp[i][k-1] + dp[k+1][j];
                    maxCoins = max(maxCoins, coins + subCoins);
                }
                dp[i][j] = maxCoins;
            }
        }
        return dp[1][n-2];
    }
};