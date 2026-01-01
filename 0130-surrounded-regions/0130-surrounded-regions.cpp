class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&canSurr,vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;
        if(board[i][j] == 'X' || canSurr[i][j] == 1) return;
        canSurr[i][j] = 1;

        dfs(i+1,j,canSurr,board);
        dfs(i,j+1,canSurr,board);
        dfs(i-1,j,canSurr,board);
        dfs(i,j-1,canSurr,board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>canSurr(n, vector<int>(m, 0));

        for(int i=0; i<n; ++i){
            if(board[i][0] == 'O' && !canSurr[i][0]){
                dfs(i,0,canSurr,board);
            }
            if(board[i][m-1] == 'O' && !canSurr[i][m-1]) {
                dfs(i,m-1,canSurr,board);
            }
        }
        for(int j=0; j<m; ++j){
            if(board[0][j] == 'O' && !canSurr[0][j]) {
                dfs(0,j,canSurr,board);
            }
            if(board[n-1][j] == 'O' && !canSurr[n-1][j]) {
                dfs(n-1,j,canSurr,board);
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j) {
                if(canSurr[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
    }
};