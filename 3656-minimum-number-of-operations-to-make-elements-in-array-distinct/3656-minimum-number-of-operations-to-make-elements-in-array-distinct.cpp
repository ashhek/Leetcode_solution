class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        
        for(int i = n-1; i>=0; --i) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1) {
                return (i + 3) / 3;
            }
        }
        return 0;
    }
};