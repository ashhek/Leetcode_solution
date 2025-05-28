class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        int startIndex = 0;
        int maxLen = 0;
        
        for(int diff = 0; diff < n; diff++) {
            for(int i=0, j=diff; j<n; i++, j++) {
                if(diff == 0) {
                    dp[i][j] = 1;
                }
                else if(diff == 1 && s[i] == s[j]) {
                   dp[i][j] = 2;
                }
                else {
                    if(s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }

                }
                if(maxLen < dp[i][j]) { 
                    maxLen = dp[i][j];
                    startIndex = i;
                }
            }
        }
        return s.substr(startIndex, maxLen);
    }
};