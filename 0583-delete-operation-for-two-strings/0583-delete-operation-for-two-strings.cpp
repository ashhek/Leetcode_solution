class Solution {
    int lcs(int i, int j, string& s, string& t) {
        if(i==0 || j==0) {
            return 0;
        }

        int len = 0;
        if(s[i-1] == t[j-1]) {
            len = max(len, 1 + lcs(i-1, j-1, s, t));
        } else {
            len = max(lcs(i-1, j, s, t), lcs(i, j-1, s, t));
        }
        return len;
    }
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        //return lcs(n, m, word1, word2);
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                int len = 0;
                if(s[i-1] == t[j-1]) {
                    len = max(len, dp[i-1][j-1]+1);
                } else {
                    len = max({len, dp[i-1][j], dp[i][j-1]});
                }
                dp[i][j] = len;
            }
        }
        int res = (n+m) - 2*dp[n][m];
        return res;
    }
};