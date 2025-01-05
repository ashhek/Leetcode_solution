class Solution {
    int dp[501][501];
    int help(int i, int j, string& s, string& t) {
        if (i == 0)
            return j;
        if (j == 0)
            return i;

        if (dp[i][j] != -1)
            return dp[i][j];

        int opr = INT_MAX;
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = min(opr, help(i - 1, j - 1, s, t));

        return dp[i][j] = 1 + min({help(i, j - 1, s, t), help(i - 1, j, s, t),help(i - 1, j - 1, s, t)});
    }

public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        // memset(dp, -1, sizeof(dp));
        // return help(n, m, word1, word2);

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; ++i) {
            dp[i][0] = i;
        }
        for(int j=0; j<=m; ++j) {
            dp[0][j] = j;
        }
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                int opr = INT_MAX;

                if(s[i-1] == t[j-1]) {
                    dp[i][j] = min(opr, dp[i-1][j-1]);
                } else {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};