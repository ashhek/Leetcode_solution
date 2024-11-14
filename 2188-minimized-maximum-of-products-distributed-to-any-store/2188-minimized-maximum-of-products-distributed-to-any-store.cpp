class Solution {
public:
    bool check(vector<int>& q, int n, int mid) {
        int i = 0;

        long long cnt = 0;
        for(int i=0; i<q.size(); ++i) {
            cnt += (q[i] / mid);
            cnt += (q[i]%mid != 0 ? 1 : 0);
        }
        return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int high = *max_element(q.begin(), q.end());
        int low = 1;
        int res;

        while(low <= high) {
            int mid = high - (high - low) / 2;

            if(check(q, n, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};