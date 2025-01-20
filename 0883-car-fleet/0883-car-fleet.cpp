class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n = speed.size();
        for(int i =0 ; i < n ; i++){
            v.push_back({position[i] , speed[i]});
        }
        sort(v.begin() , v.end());
        stack<double>st;
        for(auto it : v){
            double d = (target*1.0) - (it.first*1.0);
            double s = it.second*1.0;
            double time = (d/s);
            while(!st.empty() && st.top() <= time)st.pop();
            st.push(time);
        }
        
        return st.size();

    }
};