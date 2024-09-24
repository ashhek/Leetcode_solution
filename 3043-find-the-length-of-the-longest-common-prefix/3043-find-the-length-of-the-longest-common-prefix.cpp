class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<string>s;
        
        for(int i=0; i<n; ++i){
            string t = to_string(arr1[i]);
            string r;
            for(int j=0; j<t.size(); ++j){
                 r += t[j];
                s.insert(r);
            }
        }
        int cnt = 0;
        for(int i=0; i<m; ++i){
            string p = to_string(arr2[i]);
            string q;
            for(int j=0; j<p.size(); ++j){
                 q += p[j];
                int x = q.size();
                if(s.find(q) != s.end()){
                    cnt = max(cnt, j+1);
                }
                else break;
            }
        }
        return cnt;
    }
};