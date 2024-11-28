class Solution {
    #define pp pair<int,pair<int,int>>
    int dj(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // queue<pair<int, pair<int, int>>>q;
        // q.push({grid[i][j], {i, j}});

        // while(!q.empty()) {
        //     int rvl = q.front().first;
        //     int row = q.front().second.first;
        //     int col = q.front().second.second;
        //     q.pop();

        //     if(row == n-1 && col == m-1) return rvl;
        //     int dir[] = {0, -1, 0, 1, 0};

        //     for(int k=0; k<4; ++k){
        //         int nr = row + dir[k];
        //         int nc = col + dir[k+1];

        //         if(nr >= 0 && nr < n && nc >=0 && nc >=0 && nc < m) {

        //         }
        //     }
        // }
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        pq.push({0, {0, 0}});
        vector<vector<int>>dist(n, vector<int>(m, 1e9));

        while(!pq.empty()) {
            int removal = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int dir[] = {0, -1, 0, 1, 0};
            for(int k=0; k<4; ++k) {
                int nr = row + dir[k];
                int nc = col + dir[k+1];

                if(nr >=0 && nr < n && nc >= 0 && nc < m) {
                    if(grid[nr][nc] + removal < dist[nr][nc]) {
                        dist[nr][nc] = grid[nr][nc] + removal;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return dj(0, 0, grid);
    }
};