class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long a = accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long b = 0;
        long long res = LLONG_MAX;
        for(int i=0;i<grid[0].size();i++){
            a -= grid[0][i];
            res = min(res,max(a,b));
            b += grid[1][i];
        }
        return res;
    }
};