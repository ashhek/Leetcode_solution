class Solution {
    public long maximumTripletValue(int[] nums) {
        long res = 0;
        long maxDiff = 0;
        int maxValue = 0;

        for(int num : nums) {
            res = Math.max(res, maxDiff*num);
            maxDiff = Math.max(maxDiff, maxValue-num);
            maxValue = Math.max(maxValue, num);
        }
        return res;
    }
}