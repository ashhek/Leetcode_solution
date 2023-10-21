class Solution {
private:
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target==0) return true;
        if(i==0) return (nums[i]==target);

        if(dp[i][target] != -1) return dp[i][target];

        bool notPick = f(i-1, target, nums, dp);
        bool pick = false;
        if(nums[i]<target)
           pick = f(i-1, target-nums[i], nums, dp);

           return dp[i][target] = notPick | pick;
    }    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); int sum = 0;
        for(int i=0; i<n; ++i) sum += nums[i];
        if(sum%2) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return f(n-1, sum/2, nums, dp);
    }
};