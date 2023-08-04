class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        int offset[] = {0, 1, 0, -1, 0};
        for(int i=0; i<4; ++i){
            int nrow = row+offset[i];
            int ncol = col+offset[i+1];
            if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol] and board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis);
            }
        }
    }    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int j=0; j<m; ++j){
            if(board[0][j]=='O' and !vis[0][j]){
                dfs(0, j, board, vis);
            }
            if(board[n-1][j]=='O' and !vis[n-1][j]){
                dfs(n-1, j, board, vis);
            }
        }
        for(int i=0; i<n; ++i){
            if(board[i][0]=='O' and !vis[i][0])
            dfs(i, 0, board, vis);

            if(board[i][m-1]=='O' and !vis[i][m-1])
            dfs(i, m-1, board, vis);
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(!vis[i][j] and board[i][j]=='O')
                board[i][j] = 'X';
            }
        }
        
    }
};