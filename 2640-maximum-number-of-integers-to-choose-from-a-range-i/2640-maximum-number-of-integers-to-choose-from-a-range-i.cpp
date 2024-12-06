class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int>vis(n+1, -1);
        for(int i=0; i<banned.size(); ++i) {
            if(banned[i] <= n)
            vis[banned[i]] = 0;
        }
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == -1) {
                if (sum + i > maxSum) {
                    break;
                }
                cnt++;
                sum += i;
            }
        }
        return cnt;
    }
};