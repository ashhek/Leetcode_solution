class Solution {
    #define pp pair<int,int>
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pp, vector<pp>, greater<pp>>pq;

        for(int i=0; i<n; ++i) {
            pq.push({nums[i], i});
        }
        vector<int>vis(n, 0);
        long long score = 0;
        while(!pq.empty()) {
            int val = pq.top().first;
            int ind = pq.top().second;
            pq.pop();

            if(!vis[ind]){
                score += (val);
                vis[ind] = 1;
                if(ind+1 < n) vis[ind+1] = 1;
                if(ind-1 >=0) vis[ind-1] = 1;
            }
        }
        return score;
    }
};