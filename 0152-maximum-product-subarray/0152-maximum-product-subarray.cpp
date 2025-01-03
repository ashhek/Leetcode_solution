class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prodForward = 1;
        int prodBackward = 1;
        int maxProd = nums[0];
        for(int i=0; i<nums.size(); ++i) {
            prodForward *= nums[i];
            prodBackward *= nums[n-i-1];
            maxProd = max(maxProd, prodForward);
            maxProd = max(maxProd, prodBackward);
            if(prodForward == 0) prodForward = 1;
            if(prodBackward == 0) prodBackward = 1;
        }
        return maxProd;
    }
};