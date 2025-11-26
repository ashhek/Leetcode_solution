class Solution {
public:
    int mod = 1e9 + 7;
    int help(int i, int j, int r, vector<vector<int>>& a, vector<vector<vector<int>>>& dp, int k) {
        if (i == 0 && j == 0) return ((r + a[0][0]) % k == 0);
        if (i < 0 || j < 0) return 0;
        if (dp[i][j][r] != -1) return dp[i][j][r];
        int nr = (r + a[i][j]) % k;
        int up = help(i-1, j, nr, a, dp, k);
        int left = help(i, j-1, nr, a, dp, k);
        return dp[i][j][r] = (up + left) % mod;
    }
    int numberOfPaths(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return help(n-1, m-1, 0, a, dp, k);
    }
};
