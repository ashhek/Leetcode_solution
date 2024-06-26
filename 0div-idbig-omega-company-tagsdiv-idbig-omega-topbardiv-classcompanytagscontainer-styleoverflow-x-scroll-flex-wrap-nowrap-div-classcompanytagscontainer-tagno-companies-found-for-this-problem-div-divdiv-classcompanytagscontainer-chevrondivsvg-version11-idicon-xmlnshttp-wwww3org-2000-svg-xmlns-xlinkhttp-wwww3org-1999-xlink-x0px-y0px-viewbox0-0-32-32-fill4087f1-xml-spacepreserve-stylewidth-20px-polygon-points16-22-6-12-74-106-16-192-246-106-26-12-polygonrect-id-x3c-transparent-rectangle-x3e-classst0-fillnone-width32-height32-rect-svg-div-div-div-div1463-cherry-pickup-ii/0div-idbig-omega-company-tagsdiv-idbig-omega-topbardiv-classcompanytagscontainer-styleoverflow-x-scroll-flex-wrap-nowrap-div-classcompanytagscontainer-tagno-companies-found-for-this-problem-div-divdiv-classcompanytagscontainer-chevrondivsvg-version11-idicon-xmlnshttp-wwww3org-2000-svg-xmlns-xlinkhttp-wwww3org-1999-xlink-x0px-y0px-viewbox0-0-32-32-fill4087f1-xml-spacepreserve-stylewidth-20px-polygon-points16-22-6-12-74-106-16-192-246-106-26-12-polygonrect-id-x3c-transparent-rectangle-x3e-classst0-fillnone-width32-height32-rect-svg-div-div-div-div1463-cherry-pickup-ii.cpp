class Solution {
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(j1<0 or j2<0 or j1>=c or j2>=c) return -1e9;
        
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

         if(dp[i][j1][j2] != -1) return dp[i][j1][j2]; 

        int cherrymx = 0;
        for(int dj1 = -1; dj1<=1; ++dj1){
            for(int dj2=-1; dj2<=1; ++dj2){
                int cherry = 0;
                if(j1==j2) cherry += grid[i][j1];
                else cherry += grid[i][j1] + grid[i][j2];

                cherry += f(i+1, j1+dj1, j2+dj2, r, c, grid, dp);
                cherrymx = max(cherry, cherrymx);
            }
        }
        // int cherry = grid[i][j1];
        // if(j1!=j2) cherry += grid[i][j2];

        return dp[i][j1][j2] = cherrymx;
        
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m,-0)));

        //return f(0, 0, c-1, r, c, grid, dp);

        for(int j1=0; j1<m; ++j1){
            for(int j2=0; j2<m; ++j2){
                if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
                else dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2; i>=0; --i){
            for(int j1=0; j1<m; ++j1){
                for(int j2=0; j2<m; ++j2){
                     int cherrymx = 0;
                     for(int dj1 = -1; dj1<=1; ++dj1){
                     for(int dj2=-1; dj2<=1; ++dj2){
                     int cherry = 0;
                     if(j1==j2) cherry += grid[i][j1];
                     else cherry += grid[i][j1] + grid[i][j2];
                 if(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)    
                cherry += dp[i+1][j1+dj1][j2+dj2];
                cherrymx = max(cherry, cherrymx);
            }
        }
        dp[i][j1][j2] = cherrymx;
                }
            }
        }
        return dp[0][0][m-1];
    }
};