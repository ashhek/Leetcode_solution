class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
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

                if(nrow >=0 && nrow < n && ncol >= 0 
                   && ncol < m && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    mat[nrow][ncol] = mat[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return mat;
    }
};