class Solution {
    int help(int i, vector<int>&nums, int target) {
        
        if(target == 0 && i == 0) {
            return 1;
        }
        if(i < 0) return 0;

        int opt1 = help(i-1, nums, target-nums[i]);
        int opt2 = help(i-1, nums, target+nums[i]);

        return opt1 + opt2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        nums.insert(nums.begin(), 0);
        return help(nums.size()-1, nums, target);
    }
};