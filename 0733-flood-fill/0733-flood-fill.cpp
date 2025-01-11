class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>&image, vector<vector<int>>&vis, int color) {
        queue<pair<int,int>>q;
        q.push({i, j});
        int initColor = image[i][j];
        vis[i][j] = 1;

        int xdir[] = {0, 0, 1, -1};
        int ydir[] = {1, -1, 0, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            image[row][col] = color;

            for(int k=0; k<4; ++k) {
                int nr = row + xdir[k];
                int nc = col + ydir[k];

                if(nr>=0 && nr<image.size() && nc>=0 && nc<image[0].size() && !vis[nr][nc] && image[nr][nc] == initColor) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));
        bfs(sr, sc, image, vis, color);
        return image;
    }
};