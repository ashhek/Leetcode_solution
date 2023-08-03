class Solution {
private:
    void dfs(int row, int col, int fc, int ic, vector<vector<int>>& ans, vector<vector<int>>& image){
        ans[row][col] = fc;
        int offset[] = {0, 1, 0, -1, 0};
        int n = image.size();
        int m = image[0].size();

        for(int i=0; i<4; ++i){
            int nrow = row + offset[i];
            int ncol = col + offset[i+1];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==ic and ans[nrow][ncol] != fc){
               dfs(nrow, ncol, fc, ic, ans, image);   
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        vector<vector<int>> ans = image;

     dfs(sr, sc, color, ic, ans, image);  
        return ans;   
    }
};