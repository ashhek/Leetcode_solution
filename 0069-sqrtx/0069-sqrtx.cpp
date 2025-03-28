class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int low = 1; int high = x;
        int res = -1;

        while(low <= high) {
            long long mid = low - (low - high) / 2;
            long long k = mid * mid;

            if(k <= x) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};