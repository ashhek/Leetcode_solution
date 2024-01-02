class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(auto it:nums) mp[it]++;
        int mx = INT_MIN;
        for(auto it:mp) mx = max(mx, it.second);
        vector<vector<int>>ans(mx);

        for(auto it:mp){
            for(int i=0; i<it.second; ++i){
                ans[i].push_back(it.first);
            }
        }
        
        return ans;

    }
};