class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int count = 0;

        for(int i=1; i<meetings.size(); ++i) {
            if(meetings[i-1][1] < meetings[i][0]) {
                count += meetings[i][0] - meetings[i-1][1] -1;
            }
            meetings[i][1] = max(meetings[i-1][1], meetings[i][1]);
        }
        if(meetings[0][0] != 1) {
            count += meetings[0][0] - 1;
        }
        if(days != meetings[n-1][1]) {
            cout << meetings[n-1][1];
            count += days - meetings[n-1][1];
        }
        return count;
    }
};