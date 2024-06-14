class Solution {
public:
    int minOperations(vector<int>& nums) {
        int opr = 0;
        int n = nums.size();

        for(int i=1; i<n; ++i){
            if(nums[i]<=nums[i-1]){
                opr += (nums[i-1] + 1 - nums[i]); 
                nums[i] = nums[i-1]+1;
            }
        }
        return opr;
    }
};