class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        long long sum = 0;

        int left = 0;
        for(int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            int len = right-left+1;

            while((sum * len)>= k) {
                sum -= nums[left];
                len--;
                left++;
            }
            count += right-left+1;
        }
        return count;
    }
};