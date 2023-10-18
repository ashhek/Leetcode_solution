class Solution {
    // int f(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m){       
    //     if(j<0 or j>=matrix[0].size()) return 1e9;  
    //     if(i==0) return matrix[i][j];
        

    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     int up = matrix[i][j] + f(i-1, j, matrix, dp, m);
    //     int left = matrix[i][j] + f(i-1, j-1, matrix, dp, m);
    //     int right = matrix[i][j] + f(i-1, j+1, matrix, dp, m);

    //     return dp[i][j] = min({up, left, right});
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(m, -0));

        for(int j=0; j<m; ++j) dp[0][j] = matrix[0][j];

        for(int i=1; i<n; ++i){
            for(int j=0; j<m; ++j){
                
                int up = matrix[i][j] + dp[i-1][j];
                int left = 1e9;
                if(j-1>=0) left = matrix[i][j] + dp[i-1][j-1];
    
                int right = 1e9;
                if(j+1<m) right = matrix[i][j] + dp[i-1][j+1];
    

                dp[i][j] = min({up, left, right});
            }
        }

        int cost = 1e9;
        for(int j=0; j<m; ++j){
            cost = min(cost, dp[n-1][j]);
        }
        return cost;
    }
};