class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int>left, right;
        int n = nums.size();
        vector<int>sum;
        int e = INT_MAX;

        for(int i=0; i<n; ++i){
            e = min(e, nums[i]);
           left.push_back(e);
        }
         int f = INT_MAX;
        for(int i=n-1; i>=0; --i){
            f = min(f, nums[i]);
            right.push_back(f);
        }
        reverse(right.begin(), right.end());
        for(int i=1; i<n-1; ++i){
            int j = left[i]; int k = right[i];
            if(nums[i]>j and nums[i]>k){
                sum.push_back(nums[i]+j+k);
            }
        }
        if(sum.empty()) return -1;
         sort(sum.begin(), sum.end());
         return sum[0];
    }
};