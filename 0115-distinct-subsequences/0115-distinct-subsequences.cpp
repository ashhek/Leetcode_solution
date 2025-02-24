class Solution {
    int mod = (int)(1e9+7);
private:
    int f(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j] = f(i-1, j-1, s, t, dp) + f(i-1, j, s, t, dp);
        return dp[i][j] = f(i-1, j, s, t,dp);
    }    
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>>dp(n+1, vector<long long>(m+1, 0));
        //return f(n, m, s, t, dp);

        for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        }

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s[i-1]==t[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};