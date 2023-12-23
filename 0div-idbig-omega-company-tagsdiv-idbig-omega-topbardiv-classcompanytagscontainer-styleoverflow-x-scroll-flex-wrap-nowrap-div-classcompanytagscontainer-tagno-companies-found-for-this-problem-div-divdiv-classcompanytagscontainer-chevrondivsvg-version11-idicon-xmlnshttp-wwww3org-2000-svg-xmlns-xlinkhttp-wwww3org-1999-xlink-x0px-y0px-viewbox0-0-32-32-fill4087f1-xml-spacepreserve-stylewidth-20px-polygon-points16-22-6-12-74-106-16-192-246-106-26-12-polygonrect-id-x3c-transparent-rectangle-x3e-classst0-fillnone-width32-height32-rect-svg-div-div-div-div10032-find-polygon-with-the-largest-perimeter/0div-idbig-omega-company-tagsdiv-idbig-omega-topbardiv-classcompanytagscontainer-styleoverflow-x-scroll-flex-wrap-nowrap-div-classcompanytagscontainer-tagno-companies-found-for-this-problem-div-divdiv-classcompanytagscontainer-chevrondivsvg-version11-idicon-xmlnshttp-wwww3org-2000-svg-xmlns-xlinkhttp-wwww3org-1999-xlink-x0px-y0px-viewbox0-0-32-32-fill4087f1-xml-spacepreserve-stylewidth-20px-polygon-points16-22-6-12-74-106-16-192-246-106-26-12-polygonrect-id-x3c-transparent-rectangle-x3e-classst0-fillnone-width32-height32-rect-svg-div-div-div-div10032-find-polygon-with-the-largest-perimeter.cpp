class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(), nums.end());
        vector<long long>pref;
        int n = nums.size();
        for(int i=0; i<nums.size(); ++i){
           
            pref.push_back(sum);
             sum += nums[i];
        }
        for(int i=n-1; i>=2; --i){
            if(pref[i]>nums[i]) return pref[i] + (long long)nums[i];
        }
        return -1;
    }
};