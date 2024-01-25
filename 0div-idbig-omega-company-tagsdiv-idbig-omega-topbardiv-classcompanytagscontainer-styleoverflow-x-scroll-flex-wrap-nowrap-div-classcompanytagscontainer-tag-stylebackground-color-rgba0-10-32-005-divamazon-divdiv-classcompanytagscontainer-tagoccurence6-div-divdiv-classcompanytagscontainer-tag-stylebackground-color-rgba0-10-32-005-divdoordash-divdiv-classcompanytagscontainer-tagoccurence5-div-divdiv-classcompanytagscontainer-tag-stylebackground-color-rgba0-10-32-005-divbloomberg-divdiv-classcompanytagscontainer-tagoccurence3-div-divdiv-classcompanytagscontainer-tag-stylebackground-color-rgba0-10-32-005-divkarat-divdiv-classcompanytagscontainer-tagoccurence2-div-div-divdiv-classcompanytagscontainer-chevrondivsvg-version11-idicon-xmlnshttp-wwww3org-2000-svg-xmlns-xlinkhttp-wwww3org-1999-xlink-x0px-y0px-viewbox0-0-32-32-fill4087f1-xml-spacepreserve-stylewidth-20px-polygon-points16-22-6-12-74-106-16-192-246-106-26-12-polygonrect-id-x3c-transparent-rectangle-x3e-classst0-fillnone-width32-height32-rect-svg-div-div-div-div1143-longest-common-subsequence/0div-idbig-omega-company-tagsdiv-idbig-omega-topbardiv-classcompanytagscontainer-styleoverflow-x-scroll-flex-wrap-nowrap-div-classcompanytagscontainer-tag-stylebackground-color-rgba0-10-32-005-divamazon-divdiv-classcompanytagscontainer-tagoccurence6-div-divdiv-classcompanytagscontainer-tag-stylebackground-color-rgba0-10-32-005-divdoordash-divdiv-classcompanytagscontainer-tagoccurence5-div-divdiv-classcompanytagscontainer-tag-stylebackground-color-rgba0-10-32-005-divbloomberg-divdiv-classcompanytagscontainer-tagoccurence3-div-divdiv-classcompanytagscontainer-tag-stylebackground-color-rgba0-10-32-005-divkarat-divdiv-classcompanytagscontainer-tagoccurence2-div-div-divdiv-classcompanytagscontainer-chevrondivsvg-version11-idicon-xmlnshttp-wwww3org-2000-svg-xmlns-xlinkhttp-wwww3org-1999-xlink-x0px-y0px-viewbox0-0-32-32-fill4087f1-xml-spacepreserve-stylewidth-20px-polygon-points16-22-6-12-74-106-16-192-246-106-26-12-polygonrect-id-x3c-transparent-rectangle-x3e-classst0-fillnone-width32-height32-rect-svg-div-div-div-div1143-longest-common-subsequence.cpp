class Solution {
    int f(int i, int j, string &s, string &t, vector<vector<int>>& dp){
        if(i==0 || j==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j] = 1 + f(i-1, j-1, s, t, dp);

        return dp[i][j] = max(f(i-1, j, s, t, dp), f(i, j-1, s, t, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(); int m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        //return f(n, m, text1, text2, dp);

        vector<int>prev(m+1, 0), curr(m+1, 0);

        // for(int i=0; i<n; ++i){
        //     dp[i][0] = 0;
        // }
        // for(int i=0; i<m; ++i){
        //     dp[0][i] = 0;
        // }

        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev=curr;
        }
        return curr[m];

    }
};