class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        multiset<pair<int,int>>st;
        int ind = 0;
        for(int& num : nums) {
            st.insert({num, ind});
            ind++;
        }
        set<int>vis;
        long long score = 0;
        while(true) {
            if(st.empty()) break;
            auto x = *st.begin();
            int val = x.first;
            int ind = x.second;

            if(vis.find(ind) != vis.end()) {
                st.erase(x);
            } else {
                score += val;
                vis.insert(ind);
                if(ind+1 < n) {
                    vis.insert(ind+1);
                } 
                if(ind-1 >= 0) {
                    vis.insert(ind-1);
                }
            }
        }
        return score;
    }
};