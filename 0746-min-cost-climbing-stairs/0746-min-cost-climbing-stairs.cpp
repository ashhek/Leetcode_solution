class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int N = 1e5+10;
        int dp[N];
        memset(dp, -1, sizeof(dp));

        int n = cost.size();
        return min(solve(cost,n-1,dp), solve(cost,n-2,dp));
    }

        int solve(vector<int>& cost, int n, int dp[]){

            if(n<2) return cost[n];

            if(dp[n] != -1) return dp[n];

            return dp[n] = min(solve(cost, n-2, dp), solve(cost,n-1,dp))+cost[n];

    }
};