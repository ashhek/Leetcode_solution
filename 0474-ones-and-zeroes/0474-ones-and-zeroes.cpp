class Solution {
public:
    int dp[601][101][101];
    int largestSize(int i, vector<string>& s, int m, int n) {
        if(i == s.size()) {
            return 0;
        }

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int x = m, y = n;
        for(int idx = 0; idx < s[i].size(); ++idx) {
            if(s[i][idx] == '1') y--;
            else x--;
        }
        int take = 0;
        if(x>=0 && y >= 0) {
            take = 1 + largestSize(i+1, s, x, y);
        }
        int notTake = largestSize(i+1, s, m, n);
        return dp[i][m][n] = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return largestSize(0, strs, m, n);
    }
};