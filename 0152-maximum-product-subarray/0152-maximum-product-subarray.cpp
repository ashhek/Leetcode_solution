class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int maxProd = INT_MIN;
        for(auto it:nums){
            prod *= it;
            maxProd = max(prod, maxProd);
            if(prod==0) prod = 1;
        }
        prod = 1;
        for(int i=n-1; i>=0; --i){
            prod *= nums[i];
            maxProd = max(prod, maxProd);
            if(prod==0) prod = 1;
        }
        return maxProd;
    }
};