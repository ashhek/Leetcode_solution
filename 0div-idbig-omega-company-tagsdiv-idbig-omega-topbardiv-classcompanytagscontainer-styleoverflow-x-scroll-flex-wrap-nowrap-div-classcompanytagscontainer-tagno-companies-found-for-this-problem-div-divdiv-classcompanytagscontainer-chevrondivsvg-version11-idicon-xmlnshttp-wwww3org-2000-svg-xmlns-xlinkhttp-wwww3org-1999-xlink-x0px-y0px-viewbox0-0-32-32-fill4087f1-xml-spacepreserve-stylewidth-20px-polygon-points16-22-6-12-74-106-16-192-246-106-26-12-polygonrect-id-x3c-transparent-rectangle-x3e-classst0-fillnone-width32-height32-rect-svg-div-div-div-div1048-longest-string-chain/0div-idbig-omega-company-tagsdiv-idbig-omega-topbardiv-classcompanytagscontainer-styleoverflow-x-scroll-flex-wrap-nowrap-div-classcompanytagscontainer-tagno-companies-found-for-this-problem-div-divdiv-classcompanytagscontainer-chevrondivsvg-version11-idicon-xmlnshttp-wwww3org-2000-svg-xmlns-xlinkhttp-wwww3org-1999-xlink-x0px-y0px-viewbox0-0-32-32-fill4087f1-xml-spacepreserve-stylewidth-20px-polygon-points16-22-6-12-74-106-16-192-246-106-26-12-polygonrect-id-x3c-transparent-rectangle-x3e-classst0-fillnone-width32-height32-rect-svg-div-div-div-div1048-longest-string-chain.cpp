class Solution {
private:
    bool check(string &s, string &t){
        if(s.size() != t.size()+1) return false;
        int i = 0;
        int j = 0;
        while(i!=s.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
            if(i==s.size() and j==t.size()) return true;
        }
        return false;
    }    
    static bool cmp(string &s, string &t){
        return s.size()<t.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        vector<int>dp(n, 1);

        int len = 0;
        for(int i=0; i<n; ++i){
            for(int prev = 0; prev<i; ++prev){
                if(check(words[i], words[prev]) and 1+dp[prev]>dp[i]){
                    dp[i] = 1+dp[prev];
                }
            }
            len = max(len, dp[i]);
        }
        return len;
    }
};