class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int offset[] = {0, 1, 0, -1, 0};

        int ic = image[sr][sc];
        queue<pair<int,int>> q;
        vector<vector<int>>ans = image;

        q.push({sr,sc});
        ans[sr][sc] = color;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; ++i){
                int nrow = row + offset[i];
                int ncol = col + offset[i+1];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==ic and ans[nrow][ncol] != color){
                    q.push({nrow, ncol});
                    ans[nrow][ncol] = color;
                }
            }

        }
        return ans;
    }
};