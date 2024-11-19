class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>diff(n, 0);

        for(auto q : queries) {
            int l = q[0];
            int r = q[1];

            diff[l] -= 1;
            if(r+1 < n)
            diff[r+1] += 1;
        }
        vector<int>pref(n, 0);
        pref[0] = diff[0];
        for(int i=1; i<n; ++i) {
            pref[i] = diff[i] + pref[i-1];
        }
        for(int i=0; i<n; ++i) {
            nums[i] = nums[i] + pref[i];
            if(nums[i] > 0) return false;
        } 
        return true;

    }
};