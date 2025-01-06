class Solution {
    int help(int i, vector<int>&coins, int target, vector<vector<int>>&dp) {
        if(i == 0) {
            if(target % coins[0] == 0) return target/coins[0];
            return 1e9;
        }
        if(dp[i][target] != -1) return dp[i][target];

        int notTake = help(i-1, coins, target, dp);
        int take = 1e9;
        if(coins[i] <= target) {
            take = 1 + help(i, coins, target-coins[i], dp);
        }
        return dp[i][target] = min(notTake, take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int x = help(n-1, coins, amount, dp);
        return x >= 1e9 ? -1 : x;
    }
};