class Solution {
    int n,m;
    void dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>>&vis) {
        vis[r][c] = 1;

        int dir[] = {0, 1, 0, -1, 0};

        for(int k=0; k<4; ++k) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if(nr>=0 && nr < n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='X') {
                dfs(nr, nc, board, vis);
            }
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        int battelships = 0;

        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(board[i][j] == 'X' && !vis[i][j]) {
                    battelships++;
                    dfs(i, j, board, vis);
                }
            }
        }
        return battelships;
    }
};