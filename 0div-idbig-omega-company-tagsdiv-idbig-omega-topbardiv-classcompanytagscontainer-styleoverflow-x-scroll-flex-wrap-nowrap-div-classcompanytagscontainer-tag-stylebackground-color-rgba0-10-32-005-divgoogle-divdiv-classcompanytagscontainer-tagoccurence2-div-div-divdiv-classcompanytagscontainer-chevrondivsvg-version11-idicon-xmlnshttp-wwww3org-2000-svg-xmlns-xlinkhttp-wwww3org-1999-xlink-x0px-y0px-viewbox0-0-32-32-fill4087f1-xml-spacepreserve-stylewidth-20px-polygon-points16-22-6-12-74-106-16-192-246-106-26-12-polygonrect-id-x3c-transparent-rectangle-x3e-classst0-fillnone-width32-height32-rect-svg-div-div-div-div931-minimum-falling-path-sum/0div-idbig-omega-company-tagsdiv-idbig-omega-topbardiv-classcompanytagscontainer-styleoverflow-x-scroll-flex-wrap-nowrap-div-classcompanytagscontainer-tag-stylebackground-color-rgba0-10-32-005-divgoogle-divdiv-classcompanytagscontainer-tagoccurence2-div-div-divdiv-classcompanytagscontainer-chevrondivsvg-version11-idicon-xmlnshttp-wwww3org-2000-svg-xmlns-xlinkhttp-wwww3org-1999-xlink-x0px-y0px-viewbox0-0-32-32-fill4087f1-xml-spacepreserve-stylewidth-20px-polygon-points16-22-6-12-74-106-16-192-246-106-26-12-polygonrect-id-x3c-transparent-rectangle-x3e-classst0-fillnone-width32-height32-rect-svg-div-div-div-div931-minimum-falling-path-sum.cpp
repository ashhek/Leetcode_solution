class Solution {
    int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m){
        if(i==0) return matrix[i][j];
        if(i<0 or j<0) return 1e9;

        if(dp[i][j] != 1e9) return dp[i][j];
        
        int up = 1e9, left = 1e9, right = 1e9;
        if(i>0) up = matrix[i][j] + f(i-1, j, matrix, dp, m);
        if(i>0 and j>0) left = matrix[i][j] + f(i-1, j-1, matrix, dp, m);
        if(i>0 and j<m-1) right = matrix[i][j] + f(i-1, j+1, matrix, dp, m);

        return dp[i][j] = min({up, left, right});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(m, 1e9));
        int cost = INT_MAX;
        for(int j=0; j<m; ++j){
            cost = min(cost, f(n-1, j, matrix, dp, m));
        }
        return cost;
    }
};