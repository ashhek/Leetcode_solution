class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k == n) return true;
        if(k > n) return false;
        map<char,int>mp;
        for(char& ch : s) {
            mp[ch]++;
        }
        int odd = 0;
        int even = 0;

        int len = 0;
        for(auto it : mp) {
            if(it.second % 2 == 0) {
                len += it.second;
            } else {
                if(it.second != 1) {
                    len += (it.second-1);
                }
            }
        }
        return (n - len <= k);
    }
};