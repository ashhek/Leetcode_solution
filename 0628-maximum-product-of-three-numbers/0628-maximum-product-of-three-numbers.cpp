class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int num1 = nums[0]*nums[1]*nums[n-1];
        int num2 = nums[n-1]*nums[n-2]*nums[n-3];
        return max(num1, num2);
    }
};