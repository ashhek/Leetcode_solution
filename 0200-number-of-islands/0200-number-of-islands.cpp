class Solution {
void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
    vis[i][j] = 1;

    int dir[] = {0, -1, 0, 1, 0};

    for(int k=0; k<4; ++k){
        int nrow = i + dir[k];
        int ncol = j + dir[k+1];

        if(nrow>=0 and ncol>=0 and nrow<grid.size() and ncol<grid[0].size() and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0){
            vis[nrow][ncol] = 1;
            dfs(nrow, ncol, grid, vis);
        }
    }

}    
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1, vector<int>(m+1, 0));

        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i, j, grid, vis);
                }
                   
            }
        }
        return ans;
    }
};