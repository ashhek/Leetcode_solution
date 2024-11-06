class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n-1; ++i) {
            for(int j=0; j<n-i-1; ++j) {
                if(nums[j] > nums[j+1]) {
                    int x = __builtin_popcount(nums[j]);
                    int y = __builtin_popcount(nums[j+1]);
                    if(x != y) {
                        return false;
                    }
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return true;
        
    }
};