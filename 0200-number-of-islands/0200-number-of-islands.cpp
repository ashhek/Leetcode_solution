class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && !vis[row][col]) {
            vis[row][col] = 1;
            dfs(row - 1, col, vis, grid);
            dfs(row + 1, col, vis, grid);
            dfs(row, col - 1, vis, grid);
            dfs(row, col + 1, vis, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};
