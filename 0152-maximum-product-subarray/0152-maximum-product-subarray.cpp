class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int prod = 1;

        for(int& num : nums) {
            prod *= num; 
            maxProd = max(maxProd, prod);
            if(prod==0) prod = 1;
        }
        prod = 1;
        reverse(nums.begin(), nums.end());
        
        for(int& num : nums) {
            prod *= num; 
            maxProd = max(maxProd, prod);
            if(prod==0) prod = 1;
        }
        return maxProd;
    }
};