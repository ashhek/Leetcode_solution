class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        for(auto num:nums){
            sum += num;
        }
         ans = n*(n+1)/2 - sum;
        return ans;  
    }
};