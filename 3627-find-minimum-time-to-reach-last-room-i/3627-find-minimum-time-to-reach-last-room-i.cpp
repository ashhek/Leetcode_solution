class Solution {
public:
    #define pp pair<int, pair<int,int>>
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int dir[] = {0, -1, 0, 1, 0};
            for(int k=0; k<4; ++k) {
                int nr = row + dir[k];
                int nc = col + dir[k+1];

                if(nr >=0 && nr<n && nc >=0 && nc < m) {
                    int reqTime = moveTime[nr][nc] - time;
                    reqTime = reqTime <= 0 ? 0 : reqTime;
                    if(time + 1 + reqTime < dist[nr][nc]) {
                        dist[nr][nc] = 1 + time + reqTime;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};