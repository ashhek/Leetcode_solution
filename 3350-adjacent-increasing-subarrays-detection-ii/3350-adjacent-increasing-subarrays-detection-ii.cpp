class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int>pref(n, 0);
        vector<int>suff(n, 0);

        pref[0] = 1;
        for(int i=1; i<n; ++i) {
            if(nums[i] > nums[i-1]) {
                pref[i] = pref[i-1] + 1;
            } else {
                pref[i] = 1;
            }
        }
        suff[n-1]  = 1;
        for(int i=n-2; i>=0; --i) {
            if(nums[i] < nums[i+1]) {
                suff[i] = suff[i+1] + 1;
            } else {
                suff[i] = 1;
            }
        }
        int res = 0;
        for(int i=0; i<n-1; ++i) {
            res = max(res, min(pref[i], suff[i+1]));
        }
        return res;
    }
};