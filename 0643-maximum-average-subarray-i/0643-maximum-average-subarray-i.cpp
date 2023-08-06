class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        double sum = 0;

        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double max_sum = sum;

        for (int right = k; right < n; ++right) {
            sum += nums[right] - nums[left]; 
            max_sum = max(max_sum, sum);
            left++; 
        }

        return max_sum / k;
    }
};
