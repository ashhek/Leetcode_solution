class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0]) return -1;

        vector<vector<int>>dist(n, vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1, {0,0}});
        dist[0][0] = 1;

        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            q.pop();
            if(row==n-1 and col == m-1) return dis;

           for(int delrow = -1; delrow<=1; ++delrow){
               for(int delcol = -1; delcol<=1; ++delcol){
                   int nrow = row + delrow;
                   int ncol = col + delcol;
                   if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==0 and dis+1 < dist[nrow][ncol]){
                       
                       dist[nrow][ncol] = dist[row][col]+1;
                       
                       
                       q.push({dis+1, {nrow,ncol}});
                   }
               }
           }
        }
        return -1;
    }
};