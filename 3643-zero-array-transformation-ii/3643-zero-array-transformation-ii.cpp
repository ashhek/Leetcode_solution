class Solution {
public:
    bool isPossible(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n, 0);

        for (int i = 0; i < k; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            
            diff[l] -= val;
            if (r < n - 1) {
                diff[r + 1] += val;
            }
        }
        vector<int> pref(n, 0);
        pref[0] = diff[0];
        int cnt = pref[0] + nums[0] <= 0 ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] + diff[i];
            if (pref[i] + nums[i] <= 0) {
                cnt++;
            }
        }
        cout << cnt << endl;
        return cnt == n;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0;
        int high = queries.size();
        int res = -1;

        while (low <= high) {
            int mid = (low + high) >> 1;

            if (isPossible(nums, queries, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};