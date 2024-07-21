class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0,prevOps = 0,n = nums.size();

        for (int i=0;i<n;i++) {
            long long diff = nums[i] - target[i];

            if (diff > 0) {
                if (prevOps > 0) {
                    if (prevOps < diff) ans += diff - prevOps;
                } else {
                    ans += diff;
                }
            } else {
                if (prevOps < 0) {
                    if (prevOps > diff) ans += prevOps - diff;
                } else {
                    ans += abs(diff);
                }
            }
            prevOps = diff;
        }

        return ans;
    }
};