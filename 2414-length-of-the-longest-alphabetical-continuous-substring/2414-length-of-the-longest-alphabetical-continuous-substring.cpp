class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int mx = 1;

        for(int i=1; i<s.size(); ++i){
            if(s[i]==s[i-1]+1){
                ans++;
                mx = max(ans, mx);
            }
            else{
                ans = 1;
            }
        }
        return mx;
    }
};