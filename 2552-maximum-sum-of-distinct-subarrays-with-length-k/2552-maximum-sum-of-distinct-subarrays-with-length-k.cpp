class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        int left = 0;
        long long sum = 0;
        map<int,int>mp;

        for(int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            mp[nums[right]]++;

            while(mp[nums[right]] > 1 || (right-left+1 > k)) {
                sum -= nums[left];
                mp[nums[left]]--;
                left++;
            }

            if(right-left+1 == k) {
                res = max(res, sum);
            }
        }
        return res;
    }
};