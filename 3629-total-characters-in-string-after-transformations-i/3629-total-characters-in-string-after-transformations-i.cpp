class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char& ch : s) {
            cnt[ch - 'a']++;
        }

        const int MOD = 1e9 + 7;

        while (t--) {
            vector<int> next_cnt(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    if (i == 25) {
                        next_cnt[0] = (next_cnt[0] + cnt[i]) % MOD;
                        next_cnt[1] = (next_cnt[1] + cnt[i]) % MOD;
                    } else {
                        next_cnt[i + 1] = (next_cnt[i + 1] + cnt[i]) % MOD;
                    }
                }
            }
            cnt = next_cnt;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
};
