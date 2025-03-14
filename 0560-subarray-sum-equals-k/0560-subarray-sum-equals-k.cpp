class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mp;
        int cnt = 0;

        for(int& num : nums) {
            sum += num;
            if(sum == k) cnt++;
            if(mp.find(sum - k) != mp.end()) cnt += mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};