class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minPrefixSum = 0;
        int maxPrefixSum = 0;
        for(int num : nums) {
            sum += num;
            maxPrefixSum = max(maxPrefixSum, sum);
            minPrefixSum = min(minPrefixSum, sum);
        }
        return maxPrefixSum - minPrefixSum;
    }
};