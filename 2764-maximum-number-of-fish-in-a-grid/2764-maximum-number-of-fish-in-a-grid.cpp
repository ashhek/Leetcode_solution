class Solution {
    int bfs(int i, int j, vector<vector<int>>&grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        q.push({i, j});
        vis[i][j] = 1;
        int dir[] = {0, -1, 0, 1, 0};
        int sum = 0;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            sum += grid[r][c];

            for(int k=0; k<4; ++k) {
                int nr = r + dir[k];
                int nc = c + dir[k+1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] != 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        cout << endl;
        return sum;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j] != 0) {
                    res = max(res, bfs(i, j, grid));
                }
            }
        }
        return res;
    }
};