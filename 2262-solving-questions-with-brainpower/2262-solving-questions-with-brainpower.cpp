class Solution {
    long long dp[100005];
    long long help(int i, vector<vector<int>>& questions) {
        if (i >= questions.size())
            return 0;

        if(dp[i] != -1) return dp[i];    

        long long keep =
            questions[i][0] + help(i + questions[i][1] + 1, questions);
        long long skip = help(i + 1, questions);

        return dp[i] = max(keep, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        memset(dp, -1, sizeof(dp));
        return help(0, questions);
    }
};