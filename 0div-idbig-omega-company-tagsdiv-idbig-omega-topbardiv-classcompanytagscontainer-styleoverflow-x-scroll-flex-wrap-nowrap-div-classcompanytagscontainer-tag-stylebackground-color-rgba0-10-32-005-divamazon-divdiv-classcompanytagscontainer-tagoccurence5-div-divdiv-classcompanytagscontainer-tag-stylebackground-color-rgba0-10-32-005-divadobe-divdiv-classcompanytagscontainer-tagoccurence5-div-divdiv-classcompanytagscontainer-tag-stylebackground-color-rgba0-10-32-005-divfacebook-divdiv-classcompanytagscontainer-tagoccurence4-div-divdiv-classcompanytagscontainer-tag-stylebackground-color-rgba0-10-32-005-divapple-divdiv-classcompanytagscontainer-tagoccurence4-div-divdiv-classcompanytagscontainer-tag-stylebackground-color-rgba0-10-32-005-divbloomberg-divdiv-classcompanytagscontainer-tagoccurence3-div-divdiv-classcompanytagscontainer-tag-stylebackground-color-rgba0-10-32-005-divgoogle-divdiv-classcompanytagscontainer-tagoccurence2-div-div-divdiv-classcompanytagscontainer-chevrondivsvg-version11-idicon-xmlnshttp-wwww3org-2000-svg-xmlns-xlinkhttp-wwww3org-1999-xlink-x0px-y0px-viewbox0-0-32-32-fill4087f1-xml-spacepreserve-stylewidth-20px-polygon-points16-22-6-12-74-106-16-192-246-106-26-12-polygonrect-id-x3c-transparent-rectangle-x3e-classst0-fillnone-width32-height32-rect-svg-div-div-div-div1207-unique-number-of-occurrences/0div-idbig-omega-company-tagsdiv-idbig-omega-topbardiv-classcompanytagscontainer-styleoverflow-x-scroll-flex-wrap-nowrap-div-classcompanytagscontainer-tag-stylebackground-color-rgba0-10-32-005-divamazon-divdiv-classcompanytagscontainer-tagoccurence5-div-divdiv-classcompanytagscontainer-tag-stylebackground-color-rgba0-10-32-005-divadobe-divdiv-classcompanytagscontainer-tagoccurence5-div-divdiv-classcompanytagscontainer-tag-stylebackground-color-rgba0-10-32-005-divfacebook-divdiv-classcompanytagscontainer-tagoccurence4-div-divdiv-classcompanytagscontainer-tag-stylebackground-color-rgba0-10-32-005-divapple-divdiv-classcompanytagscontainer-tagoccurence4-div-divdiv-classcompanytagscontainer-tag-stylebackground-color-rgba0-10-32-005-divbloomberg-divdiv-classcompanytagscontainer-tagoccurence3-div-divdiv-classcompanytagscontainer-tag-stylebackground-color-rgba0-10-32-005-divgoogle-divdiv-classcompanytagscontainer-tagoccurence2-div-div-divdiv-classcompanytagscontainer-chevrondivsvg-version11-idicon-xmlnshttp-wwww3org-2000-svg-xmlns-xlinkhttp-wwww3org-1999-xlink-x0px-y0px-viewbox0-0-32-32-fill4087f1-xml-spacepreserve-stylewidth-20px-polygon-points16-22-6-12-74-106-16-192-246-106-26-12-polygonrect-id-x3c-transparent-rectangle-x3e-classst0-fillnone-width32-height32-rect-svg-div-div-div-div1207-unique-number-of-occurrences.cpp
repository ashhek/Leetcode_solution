class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int>st;
        map<int,int>mp;
        for(auto it:arr) mp[it]++;

        int cnt = 0;
        for(auto it:mp){
            st.insert(it.second);
            cnt++;
        }
        return cnt==st.size();
    }
};