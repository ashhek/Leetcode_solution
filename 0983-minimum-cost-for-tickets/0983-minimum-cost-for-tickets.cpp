class Solution {
public:
    int n;
    vector<int> dp;
    
    int help(int i, vector<int>& days, vector<int>& costs) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        
        int day1 = costs[0] + help(i + 1, days, costs);
        
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        int day7 = costs[1] + help(j, days, costs);
        
        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        int day30 = costs[2] + help(j, days, costs);
        
        return dp[i] = min(day1, min(day7, day30));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n, -1);
        return help(0, days, costs);
    }
};
