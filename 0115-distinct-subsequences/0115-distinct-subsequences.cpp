class Solution {
public:
    int mod = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>>dp(n+2, vector<long long>(m+2, 0));

        for(int i=0; i<=n; ++i) {
            dp[i][0] = 1;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                long long notTake = dp[i-1][j];
                long long take = 0;
                if(s[i-1] == t[j-1]) {
                    take = dp[i-1][j-1];
                }
                dp[i][j] = (take + notTake) % mod;
            }
        }
        return dp[n][m];
    }
};