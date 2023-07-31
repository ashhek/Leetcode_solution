class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int offset[] = {0, 1, 0, -1, 0};
        int n = grid.size();
        int m = grid[0].size();

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int nrow = row + offset[k];
                int ncol = col + offset[k + 1];
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};
