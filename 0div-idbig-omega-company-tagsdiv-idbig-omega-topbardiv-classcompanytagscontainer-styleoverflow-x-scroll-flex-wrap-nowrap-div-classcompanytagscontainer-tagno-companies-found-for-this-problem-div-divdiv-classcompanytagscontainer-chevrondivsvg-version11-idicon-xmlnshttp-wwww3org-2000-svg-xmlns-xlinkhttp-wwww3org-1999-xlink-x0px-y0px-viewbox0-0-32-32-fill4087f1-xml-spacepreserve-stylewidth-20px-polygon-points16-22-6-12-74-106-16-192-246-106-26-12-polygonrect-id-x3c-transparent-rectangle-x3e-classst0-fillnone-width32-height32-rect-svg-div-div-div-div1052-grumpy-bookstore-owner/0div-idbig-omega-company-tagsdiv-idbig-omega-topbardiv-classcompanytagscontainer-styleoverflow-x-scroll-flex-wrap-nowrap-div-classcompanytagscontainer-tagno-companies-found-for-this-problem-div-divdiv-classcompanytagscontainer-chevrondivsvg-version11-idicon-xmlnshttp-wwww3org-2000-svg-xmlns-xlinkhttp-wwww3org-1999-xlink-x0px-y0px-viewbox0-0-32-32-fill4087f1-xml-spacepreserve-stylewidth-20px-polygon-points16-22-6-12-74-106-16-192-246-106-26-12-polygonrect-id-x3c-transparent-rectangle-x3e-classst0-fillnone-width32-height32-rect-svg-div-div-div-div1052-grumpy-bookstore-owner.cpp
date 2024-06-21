class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0)
                ans += customers[i];
        }

        int sum = 0;
        int cnt = 0;
        int res = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            if (grumpy[j] == 1)
                sum += customers[j];
            cnt++;

            while (cnt > minutes) {
                cnt--;
                if (grumpy[i] == 1)
                    sum -= customers[i];
                i++;
            }
            res = max(res, sum);
        }
        return res + ans;
    }
};