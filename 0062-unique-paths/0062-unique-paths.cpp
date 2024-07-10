class Solution {
    int help(int i, int j, vector<vector<int>>&dp){
        if(i==0 && j==0)
        return 1;
        if(i<0) return 0;
        if(j<0) return 0;

        if(dp[i][j] != -1) return dp[i][j];


        int up = help(i-1, j, dp);
        int left = help(i, j-1, dp);

        return dp[i][j] = (left + up);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));


        for(int i=0; i<m; ++i) dp[i][0] = 1;
        for(int j=0; j<n; ++j) dp[0][j] = 1;

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){

                int up = dp[i-1][j];
                int left = dp[i][j-1];

                dp[i][j] = up+left;
            }
        }
        return dp[m-1][n-1];
    }
};