class Solution {
public:
    int longestPalindrome(string s) {
        vector<long long> cnt(512, 0);

        for (char ch : s) {
            cnt[ch - '0']++;
        }
        long long len = 0;
        int odd = 0;
        for (int i : cnt) {
            if(i&1) odd=1;
            len += (i&1 ? i-1 : i);
        }
        return odd==1 ? len+1 : len;
    }
};