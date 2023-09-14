class Solution {
    private:
    int helper(vector<int>&nums, vector<int>& dp, int ind){
        if(ind>=nums.size()) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        int fs =  helper(nums, dp, ind+1);
        int ss = nums[ind] + helper(nums, dp, ind+2);

        return dp[ind] = max(fs, ss);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return helper(nums, dp, 0);
    }
};