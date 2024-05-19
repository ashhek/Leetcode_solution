#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        ll ans = 0;
        ll count = 0;
        ll mini = INT_MAX;
        for (ll i : nums) {
            ll x = i;
            ll y = i ^ k;

            if (y > x)
                ans += y, count++;
            else
                ans += x;

            mini = min(mini, abs(x - y));
        }
        return count % 2 == 0 ? ans : ans - mini;
    }
};