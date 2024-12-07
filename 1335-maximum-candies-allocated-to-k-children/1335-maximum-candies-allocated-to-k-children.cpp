class Solution {
    bool check(vector<int>& nums, int mid, long long k) {
        //cout << mid << endl;
        long long cnt = 0;
        for(int num : nums) {
            cnt += (num / mid);
        }
        return (long long)cnt >= k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum < k) return false;

        long long low = 1;
        long long high = *max_element(candies.begin(), candies.end());
        int res;
        while(low <= high) {
            int mid = high - (high - low) / 2;

            if(check(candies, mid, k)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};