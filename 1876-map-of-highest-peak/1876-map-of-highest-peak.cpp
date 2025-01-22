class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int,int>>q;
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>level(n, vector<int>(m, 1e9));

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(isWater[i][j] == 1) {
                    level[i][j] = 0;
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        int dir[] = {0, -1, 0, 1, 0};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k=0; k<4; ++k) {
                int nrow = row + dir[k];
                int ncol = col + dir[k+1];

                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
                   && !vis[nrow][ncol]) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    level[nrow][ncol] = level[row][col] + 1;
                }
            }
            
        }
        return level;
    }
};