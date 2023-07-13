class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        vector<vector<int>>ans;
        int n = points.size();


        for(int i=0; i<n; ++i){
           int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
           maxh.push({dist, {points[i][0], points[i][1]}});

           if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size()>0){
            auto s =  maxh.top().second;
            vector<int> temp{s.first, s.second};
             ans.push_back(temp);
            maxh.pop();
        }
        return ans;
    }
};