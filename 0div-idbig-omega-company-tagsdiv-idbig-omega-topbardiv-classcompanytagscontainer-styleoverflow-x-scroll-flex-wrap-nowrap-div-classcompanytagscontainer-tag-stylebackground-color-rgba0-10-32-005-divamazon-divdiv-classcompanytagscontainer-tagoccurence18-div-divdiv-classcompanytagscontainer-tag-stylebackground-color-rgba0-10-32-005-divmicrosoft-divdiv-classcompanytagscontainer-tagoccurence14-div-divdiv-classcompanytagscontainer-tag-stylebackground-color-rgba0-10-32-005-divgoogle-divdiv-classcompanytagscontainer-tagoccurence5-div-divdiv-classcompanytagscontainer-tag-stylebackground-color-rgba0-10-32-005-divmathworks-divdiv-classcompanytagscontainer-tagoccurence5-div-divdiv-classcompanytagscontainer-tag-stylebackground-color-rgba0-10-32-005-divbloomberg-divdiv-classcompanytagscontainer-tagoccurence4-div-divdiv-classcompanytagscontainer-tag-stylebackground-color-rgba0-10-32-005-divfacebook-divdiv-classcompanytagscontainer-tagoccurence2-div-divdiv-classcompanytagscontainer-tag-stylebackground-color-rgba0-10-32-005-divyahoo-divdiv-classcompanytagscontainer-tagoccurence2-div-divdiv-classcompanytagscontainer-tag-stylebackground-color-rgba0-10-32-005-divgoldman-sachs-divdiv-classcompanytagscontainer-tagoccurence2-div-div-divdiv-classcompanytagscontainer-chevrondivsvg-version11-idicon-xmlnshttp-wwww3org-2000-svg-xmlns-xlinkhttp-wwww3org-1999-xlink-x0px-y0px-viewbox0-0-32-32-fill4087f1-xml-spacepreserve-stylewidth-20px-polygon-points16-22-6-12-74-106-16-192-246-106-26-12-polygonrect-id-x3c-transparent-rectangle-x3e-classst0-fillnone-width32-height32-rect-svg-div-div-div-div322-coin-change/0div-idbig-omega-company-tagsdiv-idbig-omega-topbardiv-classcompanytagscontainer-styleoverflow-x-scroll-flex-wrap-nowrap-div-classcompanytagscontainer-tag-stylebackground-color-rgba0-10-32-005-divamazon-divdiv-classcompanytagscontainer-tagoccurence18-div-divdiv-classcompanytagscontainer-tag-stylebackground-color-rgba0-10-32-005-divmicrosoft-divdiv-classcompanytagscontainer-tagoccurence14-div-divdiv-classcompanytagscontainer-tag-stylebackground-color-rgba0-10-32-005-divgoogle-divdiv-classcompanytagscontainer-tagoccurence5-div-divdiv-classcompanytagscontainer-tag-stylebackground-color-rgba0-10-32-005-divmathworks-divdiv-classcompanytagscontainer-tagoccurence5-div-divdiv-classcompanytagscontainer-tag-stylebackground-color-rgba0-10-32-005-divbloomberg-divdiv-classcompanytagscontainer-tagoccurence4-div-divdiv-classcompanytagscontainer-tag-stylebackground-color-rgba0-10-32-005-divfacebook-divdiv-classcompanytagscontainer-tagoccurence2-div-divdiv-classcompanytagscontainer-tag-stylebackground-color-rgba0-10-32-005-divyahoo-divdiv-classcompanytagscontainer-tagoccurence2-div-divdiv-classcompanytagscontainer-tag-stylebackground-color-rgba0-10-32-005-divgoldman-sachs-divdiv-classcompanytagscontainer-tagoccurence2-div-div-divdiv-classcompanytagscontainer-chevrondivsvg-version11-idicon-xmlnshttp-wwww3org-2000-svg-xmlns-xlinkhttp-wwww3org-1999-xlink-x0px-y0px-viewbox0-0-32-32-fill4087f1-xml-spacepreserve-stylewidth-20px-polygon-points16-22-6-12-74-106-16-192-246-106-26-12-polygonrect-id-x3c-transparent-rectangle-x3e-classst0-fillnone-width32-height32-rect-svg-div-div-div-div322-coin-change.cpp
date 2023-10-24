class Solution {
    int f(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i==0){
            if(target%nums[0]==0) return target/nums[0];
            else return 1e9;
        }
        if(dp[i][target]!= -1) return dp[i][target];
        int notPick = f(i-1, target, nums, dp);
        int pick = INT_MAX;
        if(target>=nums[i]) pick = 1 + f(i, target-nums[i], nums, dp);

        return dp[i][target] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        if(f(n-1, amount, coins, dp)==1e9) return -1;
        else return f(n-1, amount, coins, dp);

    }
};