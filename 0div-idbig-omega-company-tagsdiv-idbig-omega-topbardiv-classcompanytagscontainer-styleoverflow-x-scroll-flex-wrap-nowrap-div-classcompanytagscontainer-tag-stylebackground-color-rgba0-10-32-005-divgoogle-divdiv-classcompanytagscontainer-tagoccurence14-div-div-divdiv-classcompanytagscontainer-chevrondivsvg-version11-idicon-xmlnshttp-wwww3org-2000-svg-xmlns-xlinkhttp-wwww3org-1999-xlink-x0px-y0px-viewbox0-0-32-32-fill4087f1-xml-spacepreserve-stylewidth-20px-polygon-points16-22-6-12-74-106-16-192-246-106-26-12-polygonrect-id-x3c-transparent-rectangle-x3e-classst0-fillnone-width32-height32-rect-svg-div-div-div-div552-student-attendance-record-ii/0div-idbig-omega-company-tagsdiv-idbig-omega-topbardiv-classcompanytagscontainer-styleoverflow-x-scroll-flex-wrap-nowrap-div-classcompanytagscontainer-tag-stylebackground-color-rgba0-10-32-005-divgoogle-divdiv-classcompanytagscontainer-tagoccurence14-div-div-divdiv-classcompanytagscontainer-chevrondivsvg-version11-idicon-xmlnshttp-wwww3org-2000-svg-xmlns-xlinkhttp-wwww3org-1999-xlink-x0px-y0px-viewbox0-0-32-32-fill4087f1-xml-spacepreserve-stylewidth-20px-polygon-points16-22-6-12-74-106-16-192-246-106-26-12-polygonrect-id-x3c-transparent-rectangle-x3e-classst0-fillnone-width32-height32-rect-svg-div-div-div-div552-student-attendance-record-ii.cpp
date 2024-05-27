class Solution {
    int mod = 1e9+7;
    int dp[1000001][2][3];
private:
    int help(int n, int ab, int lt){
        if(ab>=2 || lt>=3)
        return 0;

        if(n==0)
        return 1;

        if(dp[n][ab][lt] != -1)
        return dp[n][ab][lt];

        int A = help(n-1, ab+1, 0)%mod;
        int L = help(n-1, ab, lt+1)%mod;
        int P = help(n-1, ab, 0)%mod;

        return dp[n][ab][lt] = ((A+L)%mod + P)%mod;
    }    
public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));

        return help(n, 0, 0);
    }
};