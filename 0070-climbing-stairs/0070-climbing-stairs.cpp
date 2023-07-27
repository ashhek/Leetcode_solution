class Solution {
public:
   
    int climbStairs(int n) {

     int N = 1e5+10;
     int dp[N];
    
     memset(dp, -1, sizeof(dp));
     return fib(n,dp);
    }

    int fib(int n, int dp[]){

        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = fib(n-1,dp)+fib(n-2,dp);
    }
};