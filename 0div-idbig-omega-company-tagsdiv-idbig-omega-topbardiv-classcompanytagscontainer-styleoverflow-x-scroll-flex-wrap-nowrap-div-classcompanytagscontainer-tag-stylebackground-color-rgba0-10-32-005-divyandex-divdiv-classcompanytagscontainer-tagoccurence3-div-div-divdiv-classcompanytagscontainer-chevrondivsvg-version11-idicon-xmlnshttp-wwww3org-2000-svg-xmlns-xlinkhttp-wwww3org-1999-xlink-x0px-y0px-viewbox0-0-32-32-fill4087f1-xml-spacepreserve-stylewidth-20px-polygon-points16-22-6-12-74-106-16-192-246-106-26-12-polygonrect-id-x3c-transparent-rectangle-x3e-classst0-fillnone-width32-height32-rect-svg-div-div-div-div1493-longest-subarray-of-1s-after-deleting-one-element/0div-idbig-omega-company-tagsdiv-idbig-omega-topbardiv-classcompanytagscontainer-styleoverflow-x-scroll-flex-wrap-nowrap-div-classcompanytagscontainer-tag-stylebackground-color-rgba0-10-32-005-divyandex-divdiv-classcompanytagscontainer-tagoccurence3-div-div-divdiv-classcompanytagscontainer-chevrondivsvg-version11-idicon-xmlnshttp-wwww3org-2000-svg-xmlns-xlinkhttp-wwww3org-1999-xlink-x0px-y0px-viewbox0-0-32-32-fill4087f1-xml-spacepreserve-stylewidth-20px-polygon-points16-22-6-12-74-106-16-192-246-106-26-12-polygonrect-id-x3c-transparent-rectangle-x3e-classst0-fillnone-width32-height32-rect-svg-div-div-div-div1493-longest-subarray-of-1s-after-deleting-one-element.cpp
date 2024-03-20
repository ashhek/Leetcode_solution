class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int i = 0;
        int ans = 0;

        for(int j=0; j<n; ++j){
            zero += (nums[j]==0);

            while(zero>1){
                zero -= (nums[i]==0);
                i++;
            }
            ans = max(ans, j-i);
        }
        return ans;
    }
};