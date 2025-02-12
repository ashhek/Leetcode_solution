class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> count(3, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        if (*min_element(count.begin(), count.end()) < k) {
            return -1;
        }

        int res = INT_MAX;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            count[s[r] - 'a']--;

            while (*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                ++l;
            }

            res = min(res, n - (r - l + 1));
        }

        return res;
    }
};
