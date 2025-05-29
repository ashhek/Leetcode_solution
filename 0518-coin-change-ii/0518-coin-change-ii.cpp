class Solution {
public:
    int findCombination(int i, int target, vector<int>& coins) {
        if (i == 0) {
            if (target % coins[0] == 0) {
                return 1;
            }
            return 0;
        }

        int take = 0;
        if (coins[i] <= target) {
            take = findCombination(i, target - coins[i], coins);
        }
        int notTake = findCombination(i - 1, target, coins);
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; ++target) {
            if (target % coins[0] == 0) {
                dp[0][target] = 1;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int target = 0; target <= amount; ++target) {
                long long take = 0;
                if (coins[i] <= target) {
                    take = dp[i][target - coins[i]];
                }
                long long notTake = dp[i - 1][target];
                dp[i][target] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};