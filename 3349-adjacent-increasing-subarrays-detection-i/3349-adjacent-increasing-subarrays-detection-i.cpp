class Solution {
private:
    bool isValid(int i, vector<int>&nums, int k) {
        for(int j=i+1; j<i+k; ++j) {
            if(nums[j] <= nums[j-1]) {
                return false;
            }
        }
        for(int j=i+k+1; j<i+k+k; ++j) {
            if(nums[j] <= nums[j-1]) {
                return false;
            }
        }
        return true;
    }    
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2*k) return false;

        for(int i=0; i <= (n - 2*k); ++i) {
            if(isValid(i, nums, k)) {
                return true;
            }
        }
        return false;
    }
};