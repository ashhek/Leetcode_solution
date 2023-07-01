class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0, mid = 0, hi = n-1;
        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[start],nums[mid]);
                start++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[hi],nums[mid]);
                hi--;
            }
        }
        return;
    }
};