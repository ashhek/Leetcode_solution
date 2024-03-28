class Solution {
public:
    #define ll long long
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<ll,ll>mp;
        priority_queue<pair<ll,ll>>pq;
        vector<ll>res(nums.size());

        for(int i=0; i<nums.size(); ++i){
            ll id = nums[i];
            ll fr = freq[i];
            mp[id] += fr;
            pq.push({mp[id], id});

            while(pq.top().first != mp[pq.top().second]){
                pq.pop();
            }
            res[i] = pq.top().first;
        }
        return res;
    }
};