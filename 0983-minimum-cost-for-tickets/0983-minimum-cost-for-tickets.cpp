class Solution {
public:
    unordered_set<int>isTravelNeeded;
    int dp[367];
    int help(int current, vector<int>&days, vector<int>&costs) {
        if(current > days[days.size()-1]) return 0;

        if(dp[current] != -1) return dp[current];

        if(isTravelNeeded.find(current) == isTravelNeeded.end()) {
            return help(current+1, days, costs);
        }
        int first = costs[0] + help(current+1, days, costs);
        int seven = costs[1] + help(current+7, days, costs);
        int thirty = costs[2] + help(current+30, days, costs);

        return dp[current] =  min({first, seven, thirty});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        for(int day : days) {
            isTravelNeeded.insert(day);
        }
        memset(dp, -1, sizeof(dp));

        return help(0, days, costs);
    }
};