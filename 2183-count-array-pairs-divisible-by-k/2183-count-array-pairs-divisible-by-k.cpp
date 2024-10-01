class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long, long long>mp;
        long long  ans = 0;

        for(int num : nums) {
            long long currGCD = __gcd(num, k);

            for(auto &[gcd, count] : mp) {
                if(gcd * currGCD % k == 0) {
                    ans += count;
                }
            }
            mp[currGCD]++;
        }
        return ans;
    }
};