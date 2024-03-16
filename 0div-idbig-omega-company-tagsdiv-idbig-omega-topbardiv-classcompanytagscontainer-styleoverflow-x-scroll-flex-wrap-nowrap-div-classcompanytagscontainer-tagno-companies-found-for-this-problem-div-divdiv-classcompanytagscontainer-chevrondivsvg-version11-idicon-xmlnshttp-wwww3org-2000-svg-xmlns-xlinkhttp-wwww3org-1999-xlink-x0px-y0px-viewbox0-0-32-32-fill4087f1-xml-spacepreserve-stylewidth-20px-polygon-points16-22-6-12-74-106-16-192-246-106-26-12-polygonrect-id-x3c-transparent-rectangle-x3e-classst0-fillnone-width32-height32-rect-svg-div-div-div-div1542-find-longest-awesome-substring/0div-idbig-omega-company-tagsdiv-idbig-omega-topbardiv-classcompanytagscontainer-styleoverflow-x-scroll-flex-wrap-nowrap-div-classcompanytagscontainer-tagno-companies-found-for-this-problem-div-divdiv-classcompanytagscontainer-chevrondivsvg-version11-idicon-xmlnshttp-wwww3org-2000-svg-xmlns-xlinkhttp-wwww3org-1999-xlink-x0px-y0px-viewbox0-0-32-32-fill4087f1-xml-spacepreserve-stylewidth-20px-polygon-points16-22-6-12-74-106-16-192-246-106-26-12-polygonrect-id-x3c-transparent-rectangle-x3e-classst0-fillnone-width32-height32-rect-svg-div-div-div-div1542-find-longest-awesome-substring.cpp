class Solution {
public:
    int longestAwesome(string s) {
        map<int,int>mp;
        int ans = 0;
        int mask = 0;

        mp[0] = -1;
        int n = s.size();

        for(int i=0; i<n; ++i){
             mask ^= 1<<(s[i] - '0');

            if(mp.find(mask)!=mp.end()){
                ans = max(ans, i-mp[mask]);
            }
            for(int d=0; d<=9; ++d){
                int newMask = (mask ^ (1<<d));
                if(mp.find(newMask)!=mp.end()){
                    ans = max(ans, i-mp[newMask]);
                }
            }
            if(mp.find(mask)==mp.end()){
                mp[mask] = i;
            }
        }
        return ans;
    }
};