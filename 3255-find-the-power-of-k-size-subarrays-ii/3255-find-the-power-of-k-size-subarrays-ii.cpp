class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> subsequenceCounts(n, 1);
        vector<int> result;


        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] + 1 == nums[i + 1]) {
                subsequenceCounts[i] = subsequenceCounts[i + 1] + 1;
            }
        }

        
        for (int i = 0; i <= n - k; ++i) {
            if (subsequenceCounts[i] >= k) {
                result.push_back(nums[i + k - 1]);
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};