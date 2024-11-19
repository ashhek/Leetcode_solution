class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        map<int,int>mp;
        int len = 0;

        for(int right = 0; right < n; ++right) {
            if(nums[right] == 0) {
                mp[nums[right]]++;
            }

            while(mp[nums[right]] > k) {
                mp[nums[left]]--;
                left++;
            }
            len = max(len, right-left+1);
        }
        return len;
    }
};