class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j] == 2) q.emplace(i, j);
                if(grid[i][j] == 1) fresh++;
            }
        }
        int time = 0;
        int directions[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty() && fresh) {
            int x = q.size();

            while(x--) {
                auto [row, col] = q.front();
                q.pop();

                for(auto dir : directions) {
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];

                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol] == 1) {
                        grid[nrow][ncol] = 2;
                        fresh--;
                        q.emplace(nrow, ncol);
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};