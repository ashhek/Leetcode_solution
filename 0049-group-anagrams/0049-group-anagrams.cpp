class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string , vector<string>> m;
        for(auto& s : strs){
            string t = s;
            sort(t.begin(), t.end());
            m[t].push_back(s);
        }
        for(auto& e : m){
            ans.push_back(e.second);
        }
        return ans;
        
    }
};