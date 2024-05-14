class Solution {
    int n, m;
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 or j < 0 or i > n or j > m or grid[i][j] == 0)
            return 0;

        int original = grid[i][j];

        int offset[] = {0, 1, 0, -1, 0};
        grid[i][j] = 0;
        int gold = 0;
        for(int k=0; k<4; ++k){
            int ni = i+offset[k];
            int nj = j+offset[k+1];

            if(ni>=0 and nj>=0 and ni<n and nj<m and grid[ni][nj]!=0)
            gold = max(gold, dfs(ni, nj, grid));
        }
        grid[i][j] = original;
        return gold + original;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(i, j, grid));
                }
            }
        }
        return maxGold;
    }
};