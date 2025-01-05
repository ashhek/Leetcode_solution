class Solution {
    int dp[501][501];
    int help(int i, int j, string& s, string &t) {
        if(i < 0) return j;
        if(j < 0) return i;
        
        if(dp[i][j] != -1) return dp[i][j];

        int opr = INT_MAX;
        int insert = INT_MAX, del = INT_MAX, rep = INT_MAX;
        if(s[i] == t[j]) {
            opr = min(opr, help(i-1, j-1, s, t));
        } else {
            insert = 1 + help(i, j-1, s, t);
            del = 1 + help(i-1, j, s, t);
            rep = 1 + help(i-1, j-1, s, t);
        }
        return dp[i][j] = min({opr, insert, del, rep});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n == 0) return m;
        if(m == 0) return n;
        memset(dp, -1, sizeof(dp));
        int x = help(word1.size()-1, word2.size()-1, word1, word2);

        return x+1;
        
    }
};