class Solution {
    int dp[301][301];
    int help(int i, int j, vector<vector<char>>& matrix) {
        if(i >= matrix.size() || j >= matrix[0].size()) return 0;
        if(matrix[i][j] == '0') {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int right = help(i, j+1, matrix);
        int down = help(i+1, j, matrix);
        int dig = help(i+1, j+1, matrix);

        return dp[i][j] = min({right, down, dig}) + 1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<matrix.size(); ++i) {
            for(int j=0; j<matrix[0].size(); ++j) {
                len = max(len, help(i, j, matrix));            }
        }
        return len*len;
    }
};