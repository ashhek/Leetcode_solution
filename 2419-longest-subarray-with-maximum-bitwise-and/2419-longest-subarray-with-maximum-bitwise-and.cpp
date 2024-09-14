class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int e = *max_element(nums.begin(), nums.end());

        int maxLen = 0;
        int currLen = 0;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]==e) {
                currLen++;
            } else {
                currLen = 0;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};