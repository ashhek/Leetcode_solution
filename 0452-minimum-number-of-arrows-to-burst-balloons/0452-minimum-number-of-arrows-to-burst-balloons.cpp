class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int arrow = n;

        sort(points.begin(), points.end());
        int last = points[0][1];

        for(int i=1; i<n; ++i) {
            if(points[i][0] <= last) {
                arrow--;
                last = min(last, points[i][1]);
            }
            else {
                last = points[i][1];
            }
        }
        return arrow;
    }
};