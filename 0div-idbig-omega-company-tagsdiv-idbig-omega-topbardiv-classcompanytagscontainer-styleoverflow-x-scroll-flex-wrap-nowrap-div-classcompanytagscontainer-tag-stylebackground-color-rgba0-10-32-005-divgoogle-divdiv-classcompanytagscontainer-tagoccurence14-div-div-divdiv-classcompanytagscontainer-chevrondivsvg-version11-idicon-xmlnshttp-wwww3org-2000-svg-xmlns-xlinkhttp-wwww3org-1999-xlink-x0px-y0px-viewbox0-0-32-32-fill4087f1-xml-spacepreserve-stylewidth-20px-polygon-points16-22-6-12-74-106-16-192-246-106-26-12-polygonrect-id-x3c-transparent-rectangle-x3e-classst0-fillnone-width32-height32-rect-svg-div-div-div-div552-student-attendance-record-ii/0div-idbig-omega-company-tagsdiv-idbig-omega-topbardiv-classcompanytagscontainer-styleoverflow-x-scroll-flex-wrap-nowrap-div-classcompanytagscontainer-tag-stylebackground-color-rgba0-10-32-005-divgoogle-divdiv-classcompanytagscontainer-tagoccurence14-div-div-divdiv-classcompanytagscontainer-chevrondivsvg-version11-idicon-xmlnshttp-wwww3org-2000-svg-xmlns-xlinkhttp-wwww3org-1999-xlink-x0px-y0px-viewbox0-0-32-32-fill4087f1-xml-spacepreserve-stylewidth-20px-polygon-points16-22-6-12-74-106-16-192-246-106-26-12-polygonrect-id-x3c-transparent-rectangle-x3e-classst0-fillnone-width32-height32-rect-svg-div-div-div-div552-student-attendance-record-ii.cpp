class Solution {
    const int MOD = 1e9 + 7;

    int help(int i, int n, int absent, int late, vector<vector<vector<int>>>& dp) {
        // If there are more than 1 absent days or more than 2 consecutive late days, it's invalid
        if (absent > 1 || late > 2) return 0;
        
        // If reached the end of the record length, it's a valid record
        if (i == n) return 1;
        
        // Check if the result is already computed
        if (dp[i][absent][late] != -1) return dp[i][absent][late];
        
        // Calculate the number of valid sequences by adding P, L, A
        int res = 0;
        
        // Append 'P'
        res = (res + help(i + 1, n, absent, 0, dp)) % MOD;
        
        // Append 'A'
        res = (res + help(i + 1, n, absent + 1, 0, dp)) % MOD;
        
        // Append 'L'
        res = (res + help(i + 1, n, absent, late + 1, dp)) % MOD;
        
        // Save the result in the DP table
        dp[i][absent][late] = res;
        
        return res;
    }

public:
    int checkRecord(int n) {
        // DP table with dimensions [n+1][2][3]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        
        // Start from the first day with no absents and no lates
        return help(0, n, 0, 0, dp);
    }
};
