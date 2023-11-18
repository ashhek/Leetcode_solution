class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 0; long sum = k;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum < (long)nums[i]*(i-j+1)) sum -= nums[j++];
        }
        return nums.size()-j;
    }
};