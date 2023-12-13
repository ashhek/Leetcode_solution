class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>rowSum(n , 0);
        vector<int>colSum(m, 0);

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
            if(grid[i][j]==1){
                rowSum[i]++;
                colSum[j]++;
            }
        }
        }
        vector<vector<int>>ans(n, vector<int>(m, 0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                int x = (2 * (rowSum[i]+colSum[j])) - (m+n);
                ans[i][j] = x;
            }
        }
        return ans;
    }
};