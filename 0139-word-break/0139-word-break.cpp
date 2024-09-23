class Solution {
    int n;
    unordered_set<string>st;
    int dp[301];
    bool help(int i, string s) {
        if(i == n) return true;

        if(dp[i] != -1) return dp[i]; 

        bool found = false;
        for(int j=i; j<n; ++j) {
            string temp = s.substr(i, j-i+1);
            if(st.count(temp)) {
                found |= help(j+1, s);
            }
        }
        return dp[i] = found;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        for(string s : wordDict) {
            st.insert(s);
        }
        return help(0, s);
    }
};