class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        vector<int>cnt(26, 0);
        for(char& ch : s) cnt[ch-'a']++;

        vector<int>pref(26, 0);
        int len = n;

        for(int i=0; i<n; ++i) {
            if(i > 0 && i < n-1) {
                if(pref[s[i]-'a'] > 0 && cnt[s[i]-'a'] - pref[s[i]-'a'] >= 2) {
                    len -= 2;
                    pref[s[i]-'a']--;
                    cnt[s[i]-'a']-=2;
                } 
            }
            pref[s[i]-'a']++;
        }
        return len;
    }
};