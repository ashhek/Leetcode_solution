class Solution {
private:
    int f(vector<vector<int>>& Grid , int i, int j, vector<vector<int>>& dp){
        if(i>=0 and j>=0 and Grid[i][j] == 1 ) return 0;
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = f(Grid, i-1, j, dp);
        int left = f(Grid, i, j-1, dp);

        return dp[i][j] = up+left;
    }    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int n = Grid.size(), m = Grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return f(Grid, n-1, m-1, dp);
    }
};