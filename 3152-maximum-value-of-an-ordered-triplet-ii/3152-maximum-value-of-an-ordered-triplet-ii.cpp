class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();

        vector<long long>prefMax(n);
        vector<long long>suffMax(n);

        prefMax[0] = (long long)nums[0];
        for(int i=1; i<n; ++i) {
            prefMax[i] = max(prefMax[i-1], (long long)nums[i]);
        }
        suffMax[n-1] = (long long)nums[n-1];
        for(int i=n-2; i>=0; --i) {
            suffMax[i] = max(suffMax[i+1], (long long)nums[i]);
        }
        
        for(int i=1; i<n-1; ++i) {
            long long val = (prefMax[i-1] - nums[i]) * suffMax[i+1];
            ans = max(ans, val);
        }
        return ans;
    }
};