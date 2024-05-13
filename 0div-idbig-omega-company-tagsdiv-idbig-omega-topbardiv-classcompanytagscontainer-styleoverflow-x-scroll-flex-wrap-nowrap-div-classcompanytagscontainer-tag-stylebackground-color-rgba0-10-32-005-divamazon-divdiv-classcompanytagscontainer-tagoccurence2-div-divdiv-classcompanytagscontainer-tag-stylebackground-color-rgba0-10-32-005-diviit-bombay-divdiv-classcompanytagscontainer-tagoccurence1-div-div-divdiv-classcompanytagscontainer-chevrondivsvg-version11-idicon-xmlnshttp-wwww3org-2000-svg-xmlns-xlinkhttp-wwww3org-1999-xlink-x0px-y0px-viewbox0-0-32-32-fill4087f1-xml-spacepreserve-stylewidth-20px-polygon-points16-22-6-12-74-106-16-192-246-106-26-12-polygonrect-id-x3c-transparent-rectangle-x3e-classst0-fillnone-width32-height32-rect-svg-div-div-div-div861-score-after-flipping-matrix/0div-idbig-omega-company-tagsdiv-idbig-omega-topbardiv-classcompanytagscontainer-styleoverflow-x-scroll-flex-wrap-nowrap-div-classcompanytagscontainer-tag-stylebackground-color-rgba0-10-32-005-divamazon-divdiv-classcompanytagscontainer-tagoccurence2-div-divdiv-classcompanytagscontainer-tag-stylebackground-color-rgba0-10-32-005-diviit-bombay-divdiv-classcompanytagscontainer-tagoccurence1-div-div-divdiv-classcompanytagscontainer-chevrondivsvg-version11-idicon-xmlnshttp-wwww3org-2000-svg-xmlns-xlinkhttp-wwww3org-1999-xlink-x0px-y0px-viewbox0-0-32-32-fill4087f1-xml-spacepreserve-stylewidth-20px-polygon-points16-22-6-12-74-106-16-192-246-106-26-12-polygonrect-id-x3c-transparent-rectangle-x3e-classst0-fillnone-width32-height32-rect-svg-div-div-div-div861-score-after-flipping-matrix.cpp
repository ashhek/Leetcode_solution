class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // modifying the first coloumn

        for (int i = 0; i < n; ++i) {
            if (grid[i][0] == 0) {

                for (int j = 0; j < m; ++j) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        // modifying the columns

        for (int j = 1; j < m; ++j) {
            int cntZero = 0;
            for (int i = 0; i < n; ++i) {
                if (grid[i][j] == 0)
                    cntZero++;
            }

            if (cntZero > n - cntZero) {
                for (int i = 0; i < n; ++i) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int score = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grid[i][j]){
                    int columnScore = grid[i][j] << (m-j-1);
                    score += columnScore;
                }
            }
        }
        return score;
    }
};