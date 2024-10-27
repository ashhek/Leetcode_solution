class Solution {
    bool isZero(int r, int c, vector<vector<int>>& matrix, int k) {
        for(int i=r; i<r+k; ++i) {
            for(int j=c; j<c+k; ++j) {
                if(i>=matrix.size() || j>=matrix[0].size()) return false;
                if(matrix[i][j] == 0) return false;
            }
        }
        return true;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;

        for (int k = 1; k <= min(n, m); ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    bool isOk = isZero(i, j, matrix, k);
                    if(isOk) cnt+=1;
                }
            }
        }
        return cnt;
    }
};