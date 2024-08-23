class Solution {
    int dp[201][201];
    int dfs(int r, int c, int par, vector<vector<int>>&matrix) {
        int dir[] = {0, -1, 0, 1, 0};
        int len = 1;
        if(dp[r][c] != -1) return dp[r][c];

        for(int k=0; k<4; ++k) {
            int nr = r + dir[k];
            int nc = c + dir[k+1];

            if(nr >=0 && nr<matrix.size() && nc>=0 &&
             nc<matrix[0].size() && par < matrix[nr][nc]) {

                len = max(len, 1 + dfs(nr, nc, matrix[nr][nc], matrix));
            }
        }
        return dp[r][c] = len;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp, -1, sizeof(dp));

        int maxLen = 1;

        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                int len = dfs(i, j,matrix[i][j], matrix);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};