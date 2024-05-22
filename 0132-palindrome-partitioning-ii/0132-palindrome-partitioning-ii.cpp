class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<=j){
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    int help(int i, string &s, vector<int>&dp){
        if(i==s.size())
        return 0;

        if(dp[i]!=-1) return dp[i];

        int mini = INT_MAX;
        for(int j=i; j<s.size(); ++j){
            if(isPalindrome(s, i, j)){
                mini = min(mini, 1 + help(j+1,s, dp));
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();

        vector<int>dp(n, -1);
        return help(0, s, dp)-1;
    }
};