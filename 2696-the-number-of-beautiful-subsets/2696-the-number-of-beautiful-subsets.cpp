class Solution {
    int backTrack(int i, vector<int>&nums, int k, unordered_map<int,int>&mp) {
        if(i == nums.size()) return 0;

        int notTake = backTrack(i+1, nums, k, mp);
        int take = 0;
        if(!mp[nums[i] + k] && !mp[nums[i] - k]) {
             mp[nums[i]]++;
             take = 1 + backTrack(i+1, nums, k, mp);
             mp[nums[i]]--;
        }
        return take + notTake;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        return backTrack(0, nums, k, mp);
    }
};