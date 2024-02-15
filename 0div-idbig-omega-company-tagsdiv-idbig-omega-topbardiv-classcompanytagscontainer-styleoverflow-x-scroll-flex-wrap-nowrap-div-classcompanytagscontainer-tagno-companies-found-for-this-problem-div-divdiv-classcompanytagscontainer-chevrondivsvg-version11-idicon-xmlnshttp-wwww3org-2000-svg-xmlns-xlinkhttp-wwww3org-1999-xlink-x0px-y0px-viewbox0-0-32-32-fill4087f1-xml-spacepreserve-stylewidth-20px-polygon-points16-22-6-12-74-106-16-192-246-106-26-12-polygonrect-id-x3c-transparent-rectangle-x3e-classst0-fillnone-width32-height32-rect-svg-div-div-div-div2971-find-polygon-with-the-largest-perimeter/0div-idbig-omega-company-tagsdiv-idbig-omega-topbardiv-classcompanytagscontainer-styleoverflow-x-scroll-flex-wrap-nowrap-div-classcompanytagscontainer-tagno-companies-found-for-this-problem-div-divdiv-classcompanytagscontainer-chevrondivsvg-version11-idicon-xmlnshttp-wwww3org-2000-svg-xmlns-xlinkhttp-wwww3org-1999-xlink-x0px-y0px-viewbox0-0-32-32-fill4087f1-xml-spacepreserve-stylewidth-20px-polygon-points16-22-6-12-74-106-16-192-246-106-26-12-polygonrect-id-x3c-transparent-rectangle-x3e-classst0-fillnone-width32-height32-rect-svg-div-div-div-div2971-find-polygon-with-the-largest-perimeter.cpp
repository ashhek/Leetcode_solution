class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long n = nums.size();
         std::sort(nums.begin(), nums.end());
         std::vector<long long>pref(n,0);

         pref[0] = nums[0];
        for(int i=1; i<n; ++i){
            pref[i] = nums[i]+pref[i-1];
        }
        
        long long ans = 0;
        for(int i=2; i<n; ++i){
            if(pref[i-1]>nums[i])
            ans = max(ans, pref[i-1]+nums[i]);
        }
        return ans==0 ? -1 : ans;
    }
};