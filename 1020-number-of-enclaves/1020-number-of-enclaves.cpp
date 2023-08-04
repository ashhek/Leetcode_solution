class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        int offset[] = {0, 1, 0, -1, 0};
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

        for(int i=0; i<4; ++i){
            int nrow = row+offset[i];
            int ncol = col+offset[i+1];

            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});   
            }
           }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int j=0; j<m; ++j){
            if(grid[0][j]==1 and !vis[0][j])
            bfs(0, j, grid, vis);

            if(grid[n-1][j]==1 and !vis[n-1][j])
            bfs(n-1, j, grid, vis);
        }
        for(int i=0; i<n; ++i){
            if(grid[i][0]==1 and !vis[i][0])
            bfs(i, 0, grid, vis);

            if(grid[i][m-1]==1 and !vis[i][m-1])
            bfs(i, m-1, grid, vis);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==1 and !vis[i][j])
                count++;
            }
        }
        return count;
    }
};