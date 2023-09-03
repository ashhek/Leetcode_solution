class Solution {
public:
    int f(int i, int buy, int cnt, vector<int> &price, vector<vector<vector<int>>> &dp){

        if(price.size()==i || cnt==2)
        return 0;
        if(dp[i][buy][cnt] != -1) 
        return dp[i][buy][cnt];
        

        int maxi = -1e9;

        if(buy)
        maxi = max(price[i]+f(i+1,0, cnt+1, price, dp), f(i+1,1, cnt,price, dp));
        else
        maxi = max(-price[i]+f(i+1,1, cnt,price, dp), f(i+1,0, cnt,price, dp));

        return dp[i][buy][cnt] =  maxi;

    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2,-1)));

        return f(0,0, 0,prices, dp);
    }
};