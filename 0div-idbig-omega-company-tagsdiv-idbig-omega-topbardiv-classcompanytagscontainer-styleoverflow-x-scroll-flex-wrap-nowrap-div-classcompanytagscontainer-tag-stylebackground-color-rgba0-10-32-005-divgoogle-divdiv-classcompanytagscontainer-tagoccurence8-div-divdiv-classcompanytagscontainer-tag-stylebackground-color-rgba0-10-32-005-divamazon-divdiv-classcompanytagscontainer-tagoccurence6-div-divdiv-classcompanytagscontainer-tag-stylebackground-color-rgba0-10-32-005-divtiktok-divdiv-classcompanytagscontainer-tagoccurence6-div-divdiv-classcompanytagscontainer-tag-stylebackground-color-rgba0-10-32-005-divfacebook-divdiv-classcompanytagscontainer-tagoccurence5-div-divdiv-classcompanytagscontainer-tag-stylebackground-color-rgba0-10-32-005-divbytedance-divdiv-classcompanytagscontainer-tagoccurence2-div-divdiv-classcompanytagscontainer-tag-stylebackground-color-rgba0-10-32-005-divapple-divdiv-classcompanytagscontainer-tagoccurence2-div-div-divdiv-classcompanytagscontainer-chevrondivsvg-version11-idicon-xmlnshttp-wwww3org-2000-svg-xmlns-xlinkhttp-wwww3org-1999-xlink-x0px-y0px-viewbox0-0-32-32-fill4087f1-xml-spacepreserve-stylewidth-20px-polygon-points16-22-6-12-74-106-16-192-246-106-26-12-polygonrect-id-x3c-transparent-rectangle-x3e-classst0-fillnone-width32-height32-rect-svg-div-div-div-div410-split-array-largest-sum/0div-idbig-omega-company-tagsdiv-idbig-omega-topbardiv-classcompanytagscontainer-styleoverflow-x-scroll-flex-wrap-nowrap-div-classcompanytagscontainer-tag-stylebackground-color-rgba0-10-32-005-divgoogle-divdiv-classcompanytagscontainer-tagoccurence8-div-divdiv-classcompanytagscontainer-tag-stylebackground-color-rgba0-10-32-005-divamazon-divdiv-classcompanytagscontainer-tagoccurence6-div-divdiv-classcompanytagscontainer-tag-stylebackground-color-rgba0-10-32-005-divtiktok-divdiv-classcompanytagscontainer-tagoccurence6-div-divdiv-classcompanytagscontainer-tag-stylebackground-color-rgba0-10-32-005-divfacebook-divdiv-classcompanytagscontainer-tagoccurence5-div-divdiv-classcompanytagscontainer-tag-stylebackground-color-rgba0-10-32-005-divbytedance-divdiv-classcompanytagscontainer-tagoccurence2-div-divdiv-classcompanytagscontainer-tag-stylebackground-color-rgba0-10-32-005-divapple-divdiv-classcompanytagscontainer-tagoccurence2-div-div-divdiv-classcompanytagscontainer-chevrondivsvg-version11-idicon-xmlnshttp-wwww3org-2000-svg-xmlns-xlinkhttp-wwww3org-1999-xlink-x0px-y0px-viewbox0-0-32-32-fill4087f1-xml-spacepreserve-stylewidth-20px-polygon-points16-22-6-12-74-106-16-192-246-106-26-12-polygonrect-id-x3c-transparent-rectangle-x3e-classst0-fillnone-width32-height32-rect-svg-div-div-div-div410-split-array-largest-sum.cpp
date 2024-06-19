class Solution {
    int check(vector<int>& nums, int maxSum){
        int cnt = 1;
        int sum = 0;

        for(int num : nums){
            if(sum + num > maxSum){
                cnt++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return cnt;

    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;

        while(l <= r){
            int mid = r - (r - l) / 2;
            if(check(nums, mid) <= k){
                sum = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return sum;
    }
};