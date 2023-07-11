class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(t.begin(), t.end());
        sort(s.begin(), s.end());
        int n = t.size();
        char ans = t[n-1];
        for(int i=0; i<t.size(); ++i){
            if(t[i] != s[i]){
                ans = t[i];
                break;
            }
        }
        return ans;
        
    }
};