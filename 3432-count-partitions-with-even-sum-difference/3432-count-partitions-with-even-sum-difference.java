class Solution {
    public int countPartitions(int[] nums) {
        int n = nums.length;

        int ans = 0;
        int leftSum = 0;

        for(int i=0; i<n-1; ++i) {
            leftSum += nums[i];
            int rightSum = 0;

            for(int j=i+1; j<n; ++j) {
                rightSum += nums[j];
            }
            if((leftSum - rightSum) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
}