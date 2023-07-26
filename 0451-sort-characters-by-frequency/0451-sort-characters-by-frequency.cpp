class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        priority_queue<pair<int,int>>maxh;
        unordered_map<int,int> m;

        for(auto it:s) m[it]++;

        for(auto it:m){
            maxh.push({it.second ,  it.first});
        }
        string ans;
        while(maxh.size() > 0){
            int m = maxh.top().first;
              
            for(int i=0; i<m; ++i) 
            ans.push_back(maxh.top().second);

            maxh.pop();
        }
        return ans;
    }
};