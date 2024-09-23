class Solution {
public:
    int n;
    unordered_set<string>st;
    int dp[51];

    int help(int i, string &s) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = 1 + help(i+1, s);
        for(int j=i; j<n; ++j) {
            string temp = s.substr(i, j-i+1);
            if(st.count(temp)) {
                take = min(take, help(j+1, s));
            }
        }
        return dp[i] = take;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        memset(dp, -1, sizeof(dp));

        for(string s : dictionary) {
            st.insert(s);
        }
        return help(0, s);
    }
};