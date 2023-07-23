class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int start = newInterval[0], end = newInterval[1];
        for(int i=0; i<intervals.size(); i++){
            if(end < intervals[i][0] || start > intervals[i][1]){
                if(start > intervals[i][1]){  
                    res.push_back(intervals[i]);
                }
                else{
                    res.push_back({start, end});
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({start, end});
        return res;
    }
};