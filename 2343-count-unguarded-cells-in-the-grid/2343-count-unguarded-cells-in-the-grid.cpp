class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (auto& w : walls) grid[w[0]][w[1]] = -1; 
        for (auto& g : guards) grid[g[0]][g[1]] = 3; 

        int dir[] = {0, -1, 0, 1, 0};


        for (auto& g : guards) {
            for (int k=0; k<4; ++k) {
                int x = g[0], y = g[1];
                while (true) {
                    x += dir[k];
                    y += dir[k+1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == -1 || grid[x][y] == 3) 
                        break;
                    if (grid[x][y] == 0) 
                        grid[x][y] = 2;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) 
                    cnt++;
            }
        }
        return cnt;
    }
};
