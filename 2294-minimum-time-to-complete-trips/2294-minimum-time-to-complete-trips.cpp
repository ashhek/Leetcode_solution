class Solution {
    bool isOk(vector<int>&time, long long k, int limit) {
        long long cnt = 0;
        for(int i=0; i<time.size(); ++i) {
            cnt += k/time[i];
        }
        return cnt >= (long long)limit;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long low = 1;
        long long high = 1e14;
        long long minTime;
        while(low <= high) {
            long long mid = high - (high - low) / 2;
            if(isOk(time, mid, totalTrips)) {
                minTime = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minTime;
    }
};