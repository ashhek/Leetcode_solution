class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int len = 0;
        int used = 0;

        for(int right = 0; right < n; ++right) {
            while((used & nums[right]) != 0) {
                used ^= nums[left++];
            }
            used |= nums[right];
            len = max(len, right-left+1);
        }
        return len;
    }
};