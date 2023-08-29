class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        
        for(auto it:nums){
            if(it != mx and it != mn) return it;
        }
        return -1;
    }
};