class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0; i<n; ++i){
            map<int,int>mp;
            for(auto it : pick){
                int ind = it[0];
                int take = it[1];
                
                if(ind==i){
                    mp[take]++;
                }
            }
            int cnt = 0;
            for(auto it : mp){
                cnt = max(cnt, it.second);
            }
            if(cnt > i) ans++;
        }
        return ans;
        
    }
};