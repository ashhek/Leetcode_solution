#define pp pair<ll, pair<ll, ll>>
#define ll long long
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});

        vector<vector<ll>> time(n, vector<ll>(m, LLONG_MAX));
        int dir[] = {0, -1, 0, 1, 0};

        while (!pq.empty()) {
            ll cost = pq.top().first;
            ll row = pq.top().second.first;
            ll col = pq.top().second.second;
            pq.pop();

            time[row][col] = cost;

            for (int k = 0; k < 4; ++k) {
                ll nrow = row + dir[k];
                ll ncol = col + dir[k + 1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    ll waitTime = max(cost, (ll)grid[nrow][ncol]) + 1;

                    if(waitTime < time[nrow][ncol]) {
                        time[nrow][ncol] = waitTime;
                        pq.push({time[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return time[n-1][m-1];
    }
};