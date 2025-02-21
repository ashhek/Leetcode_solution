class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxSum1 = nums[0];

        for(int num : nums) {
            sum += num;
            if(sum < 0) {
                sum = 0;
            }
            maxSum1 = max(maxSum1, sum);
        }
        sum = 0;
        int maxSum2 = nums[n-1];
        for(int i=n-1; i>=0; --i) {
            sum += nums[i];
            if(sum > 0) {
                sum = 0;
            }
            maxSum2 = max(maxSum2, abs(sum));
        }
        int maxAbsoluteSum = max(maxSum1, maxSum2);
        return maxAbsoluteSum;
    }
};