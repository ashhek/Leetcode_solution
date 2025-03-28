class Solution {
    bool isOk(vector<int>&nums, int k, int h) {
        long long hrs = 0;
        for(int num : nums) {
            if(num < k) {
                hrs++;
            } else {
                hrs += (num+k-1)/k;
            }
        }
        return hrs <= (long long)h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());

        long long res = 0;
        while(low <= high) {
            long long mid = low - (low - high) / 2;

            if(isOk(piles, mid, h)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};