class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        int xr = nums[0];
        long long count = 0;
        if(nums[0] == 0) count++;
        mp[nums[0]]++;

        for(int i=1; i<nums.size(); ++i) {
            xr ^= nums[i];

            if(xr == 0) {
                count++;
            }
             if(mp.find(xr) != mp.end()) {
                 count += mp[xr];
            }
            mp[xr]++;
        }
        return count;
    }
};