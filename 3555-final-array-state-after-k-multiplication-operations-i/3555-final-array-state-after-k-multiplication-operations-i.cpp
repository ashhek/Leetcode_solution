class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i=0; i<k; ++i) {
            int x = *min_element(nums.begin(), nums.end());
            for(int j=0; j<nums.size(); ++j) {
                if(nums[j]==x) {
                    nums[j] = x*multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};