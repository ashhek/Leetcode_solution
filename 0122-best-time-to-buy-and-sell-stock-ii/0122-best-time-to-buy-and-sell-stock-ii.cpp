class Solution {
private:
    int f(int i, int buy, vector<int>&prices, vector<vector<int>>&dp){
        
        if(i==prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i+1, 0, prices, dp),  f(i+1, 1, prices, dp));
        }
        else{  
            profit = max(prices[i] + f(i+1, 1, prices ,dp) , f(i+1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }    
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        //return f(0, 1, prices, dp);

        dp[n][1] = dp[n][0] = 0;

       for(int i=n-1; i>=0; --i){
           for(int j=0; j<=1; ++j){
               if(j==1) dp[i][j] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
               else dp[i][j] = max(prices[i]+dp[i+1][1], dp[i+1][0]);
           }
       }
        return dp[0][1];

    }
};