class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int>cnt(26, 0);
        for(char ch : s1) cnt[ch-'a']++;
        int left = 0;
        for(int right=0; right<m; ++right) {
            if(right >= n) {
                cnt[s2[left]-'a']++;
                left++;
            }
            cnt[s2[right]-'a']--;
            if(right >= n-1) {
                bool found = false;
                for(int i=0; i<26; ++i) {
                    if(cnt[i]) {
                        found = true;
                        break;
                    }
                }
                if(!found) return true;
            }
        }
        return false;
    }
};
