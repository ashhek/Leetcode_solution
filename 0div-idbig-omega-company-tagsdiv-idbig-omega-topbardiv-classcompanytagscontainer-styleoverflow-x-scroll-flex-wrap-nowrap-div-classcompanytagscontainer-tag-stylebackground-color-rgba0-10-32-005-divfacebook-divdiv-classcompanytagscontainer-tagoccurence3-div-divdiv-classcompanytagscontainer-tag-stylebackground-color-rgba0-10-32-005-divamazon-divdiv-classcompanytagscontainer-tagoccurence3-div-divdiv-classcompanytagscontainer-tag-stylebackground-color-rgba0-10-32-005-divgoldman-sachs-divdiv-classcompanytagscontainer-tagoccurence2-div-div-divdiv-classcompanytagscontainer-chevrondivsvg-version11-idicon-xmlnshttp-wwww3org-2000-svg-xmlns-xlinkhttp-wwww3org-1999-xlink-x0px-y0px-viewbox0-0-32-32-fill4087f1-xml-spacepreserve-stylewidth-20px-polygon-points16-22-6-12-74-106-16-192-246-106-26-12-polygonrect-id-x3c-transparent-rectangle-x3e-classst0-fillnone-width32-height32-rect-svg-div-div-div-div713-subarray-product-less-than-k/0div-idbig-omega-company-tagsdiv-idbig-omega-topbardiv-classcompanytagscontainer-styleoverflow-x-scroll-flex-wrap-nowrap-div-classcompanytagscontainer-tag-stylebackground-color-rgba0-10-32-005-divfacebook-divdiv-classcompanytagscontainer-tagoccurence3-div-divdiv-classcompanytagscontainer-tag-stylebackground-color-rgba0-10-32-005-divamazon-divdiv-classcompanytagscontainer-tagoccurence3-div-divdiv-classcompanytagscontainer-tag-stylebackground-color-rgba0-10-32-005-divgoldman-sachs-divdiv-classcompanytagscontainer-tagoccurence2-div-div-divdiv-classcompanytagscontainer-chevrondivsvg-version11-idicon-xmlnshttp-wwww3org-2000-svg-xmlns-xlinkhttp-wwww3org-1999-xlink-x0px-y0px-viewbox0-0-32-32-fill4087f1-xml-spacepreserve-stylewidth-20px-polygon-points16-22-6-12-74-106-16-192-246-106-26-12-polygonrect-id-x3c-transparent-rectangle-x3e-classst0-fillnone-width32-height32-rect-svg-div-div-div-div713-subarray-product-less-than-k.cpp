class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int i = 0;
        int prod = 1;
        int r = 0;
        bool flag = false;
    
        for(int j=0; j<nums.size(); ++j){
            prod *= nums[j];

            while(prod>=k and i<=j){
                prod /= nums[i];
                i++;
            }
           
           ans += (j-i+1);
        }
    
        return ans < 0 ? 0 : ans;
    }
};