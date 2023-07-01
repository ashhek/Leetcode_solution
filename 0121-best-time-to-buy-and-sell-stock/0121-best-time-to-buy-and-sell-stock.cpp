class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int effprice = prices[0];
        int profit = 0;
        for(int i=0; i<n; ++i){
           profit = max(profit, prices[i]-effprice);
           effprice = min(effprice, prices[i]);
        }
        return profit;
    }
};