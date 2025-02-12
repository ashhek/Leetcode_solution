class Solution {
    int sum(int n) {
        int s = 0;
        while (n) {
            s += (n % 10);
            n /= 10;
        }
        return s;
    }

public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int num : nums) {
            int digitSum = sum(num);
            arr.push_back({digitSum, num});
        }
        sort(arr.rbegin(), arr.rend());
        int ans = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i].first == arr[i + 1].first) {
                ans = max(ans, arr[i].second + arr[i + 1].second);
            }
        }
        return ans;
    }
};