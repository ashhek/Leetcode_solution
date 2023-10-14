class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size()<1) return 0;

        int ans = 0;
        for(int i=0; i<nums.size()-1; ++i){
            ans = max(ans, abs(nums[i]-nums[i+1]));
        }
        return ans;
    }
};