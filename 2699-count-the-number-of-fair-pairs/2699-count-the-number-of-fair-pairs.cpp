class Solution {
public:
    long long countAtLeastSum(vector<int>& nums, int upper) {
        long long cnt = 0;
        int j = nums.size() - 1;
        for(int i=0; i<j; ++i) {
            while(i < j && nums[i] + nums[j] > upper) {
                j--;
            }
            cnt += j-i;
        }
        return cnt;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countAtLeastSum(nums, upper) - countAtLeastSum(nums, lower-1);
    }
};