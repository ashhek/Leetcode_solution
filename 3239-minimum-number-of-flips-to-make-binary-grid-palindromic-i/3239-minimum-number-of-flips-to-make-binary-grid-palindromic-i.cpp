class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int rowFlips = 0, colFlips = 0;

        for (int i = 0; i < n; ++i) {
            int j = 0, k = m - 1;
            int rowFlip = 0;
            while (j < k) {
                if (grid[i][j] != grid[i][k])
                    rowFlip++;
                j++;
                k--;
            }
            rowFlips += rowFlip;
        }

        for (int j = 0; j < m; ++j) {
            int i = 0, k = n - 1;
            int colFlip = 0;
            while (i < k) {
                if (grid[i][j] != grid[k][j])
                    colFlip++;
                i++;
                k--;
            }
            colFlips += colFlip;
        }

        return min(rowFlips, colFlips);
    }
};
