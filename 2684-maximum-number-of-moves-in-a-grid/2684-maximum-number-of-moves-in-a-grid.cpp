class Solution {
    int dp[1001][1001];
    int n, m;
public:
    int help(int i, int j, int prev, vector<vector<int>>& grid) {
        if(i < 0 || i>=n || j<0 || j>=m) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = 0, up = 0, down = 0;
        if(i-1 >= 0 && j+1 < m && grid[i-1][j+1] > prev) {
            up = 1+help(i-1, j+1, grid[i-1][j+1], grid);
        }
        if(j+1 < m && grid[i][j+1] > prev) {
            down = 1 + help(i, j+1, grid[i][j+1], grid);
        }
        if(i+1 < n && j+1 < m && grid[i+1][j+1] > prev) {
            right = 1 + help(i+1, j+1, grid[i+1][j+1], grid);
        }
        return dp[i][j] = max({up, down, right});
        
    }
    int maxMoves(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();
        memset(dp, -1, sizeof(dp));

        int maxMove = 0;

        for(int i=0; i<n; ++i){
            int x = help(i, 0, grid[i][0], grid);
            maxMove = max(maxMove, x);
        }
        return maxMove;
    }
};