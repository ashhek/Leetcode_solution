class Solution {
    int dp[501][501];
    int lcs(int i, int j, string& s, string& t) {
        if(i<0 || j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) {
            return dp[i][j] = 1 + lcs(i-1, j-1, s, t);
        }
            return dp[i][j] = max(lcs(i-1, j, s, t), lcs(i, j-1, s, t));
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        string t = s;
        reverse(t.begin(), t.end());

        return n - lcs(n-1,n-1,s,t);
    }
};