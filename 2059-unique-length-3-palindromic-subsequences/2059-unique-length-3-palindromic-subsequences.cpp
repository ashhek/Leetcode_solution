class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>first(26, INT_MAX);
        int last[26] = {};
        for (int i = 0; i < n; ++i) {
            first[s[i] - 'a'] = min(first[s[i]-'a'], i);
            last[s[i] - 'a'] = i;
        }
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            if (first[i] < last[i]) {
                unordered_set<char> st(s.begin() + first[i] + 1,
                                   s.begin() + last[i]);
                cnt += st.size();
            }
        }
        return cnt;
    }
};