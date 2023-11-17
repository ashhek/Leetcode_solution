class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>cnt(1e5+1, 0);
        for(auto num:nums){
            cnt[num]++;
        }
        int i = 1;
        int j = 1e5;
        int maxSum = 0;
        while(i<=j){
            if(cnt[i]==0) {
                i++; continue;
            }
            if(cnt[j]==0) {
                j--; continue;
            }
            maxSum = max(maxSum, i+j);
            cnt[i]--; cnt[j]--;
        }
        return maxSum;
    }
};