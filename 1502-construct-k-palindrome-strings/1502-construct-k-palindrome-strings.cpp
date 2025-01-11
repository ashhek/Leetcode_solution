class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k == n) return true;
        if(k > n) return false;

        int cnt[26] = {0};
        for(char& ch : s) {
            cnt[ch - 'a']++;
        }
        
        int maxPossibleLen = 0;
        for(int i=0; i<26; ++i) {
            if(cnt[i] % 2 == 0) {
                maxPossibleLen += cnt[i];
            } else {
                if(cnt[i] != 1) {
                    maxPossibleLen += (cnt[i]-1);
                }
            }
        }
        return (n - maxPossibleLen <= k);
    }
};