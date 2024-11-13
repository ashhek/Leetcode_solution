class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[2] < b[2]; }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        sort(trips.begin(), trips.end(), cmp);
        int m = trips[n - 1][2];
        vector<int> diff(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            int l = trips[i][1];
            int r = trips[i][2];

            diff[l] += trips[i][0];
            diff[r] -= trips[i][0];
        }
        vector<int> pref(m + 1, 0);
        pref[0] = diff[0];
        for (int i = 1; i <= m; ++i) {
            pref[i] = pref[i - 1] + diff[i];
        }
        for (int i = 0; i <= m; ++i) {
            if (pref[i] > capacity)
                return false;
        }
        return true;
    }
};