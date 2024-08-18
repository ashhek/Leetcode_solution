class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = -1;

        for(int& num : nums) {
            int idx = lower_bound(nums.begin(), nums.end(), num) - nums.begin();
            if( idx == nums.size()-1){
                return nums[idx];
            }
            if(nums[idx+1] != num){
                return num;
            }
        }
        return -1;
    }
};