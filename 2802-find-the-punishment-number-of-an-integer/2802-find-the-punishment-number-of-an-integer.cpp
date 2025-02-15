class Solution {
    bool partition(int i, string& s, int sum, int n) {
        if(i == s.size()) return sum == n;
        int num = 0;
        for(int j = i; j < s.size(); ++j) {
            num = num * 10 + (s[j] - '0');
            if(num + sum > n) break;
            if(partition(j + 1, s, sum + num, n)) return true;
        }
        return false;
    }

    bool check(int n) {
        string s = to_string(n * n);
        return partition(0, s, 0, n);
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(check(i)) ans += (i * i);
        }
        return ans;
    }
};
