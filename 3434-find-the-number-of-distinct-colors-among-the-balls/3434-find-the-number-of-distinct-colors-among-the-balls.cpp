class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> col;
        map<int,set<int>> mp;
        vector<int> ans;
        for(auto i: queries){
            int x = i[0], y = i[1];
            if(col[x]==0) {
                mp[y].insert(x);
                col[x] = y;
            } else {
                int z = col[x];
                mp[z].erase(x);
                if(mp[z].size()==0) 
                    mp.erase(z);
                mp[y].insert(x);
                col[x] = y;
            }
            ans.push_back(mp.size());
        }
        
        return ans;
    }
};