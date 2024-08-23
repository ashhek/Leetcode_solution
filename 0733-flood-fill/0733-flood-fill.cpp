class Solution {
    void dfs(int r, int c, vector<vector<int>>& image, int ic, int fc) {
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size()) return;
        if(image[r][c] != ic) return;

        image[r][c] = fc;

        dfs(r-1, c, image, ic, fc);
        dfs(r+1, c, image, ic, fc);
        dfs(r, c-1, image, ic, fc);
        dfs(r, c+1, image, ic, fc);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic = image[sr][sc];
        if(ic != color)
        dfs(sr, sc, image, ic, color);
        return image;
    }
};