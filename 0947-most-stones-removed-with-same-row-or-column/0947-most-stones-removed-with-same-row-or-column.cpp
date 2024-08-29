class Solution {
    int dfs(int ind, vector<vector<int>>& stones, vector<int>& vis) {
        vis[ind] = 1;

        int cnt = 0;
        for(int i=0; i<stones.size(); ++i) {
            if(!vis[i] && (stones[ind][0] == stones[i][0] || stones[ind][1]==stones[i][1])){
                cnt += 1 + dfs(i, stones, vis);
            }
        }
        return cnt;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int>vis(n, 0);

        int res = 0;
        for(int i=0; i<n; ++i) {
            if(!vis[i]) {
                res += dfs(i, stones, vis);
            }
        }
        return res;
    }
};