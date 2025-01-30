class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
    
      

        queue<pair<int,int>> q;
        int fcount = 0;
        int offset[5] = {0, 1, 0 , -1, 0};

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fcount++;
            }
        }
        if(fcount==0) return 0;
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; ++i){
                int nrow = x + offset[i];
                int ncol = y + offset[i+1];

                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1){
                    grid[nrow][ncol] = 2;
                    q.push({nrow,ncol});
                    fcount--;
                }
            }
            }
            ans++;
            
        }
        return (fcount==0 ? ans-1  : -1);
    }
};