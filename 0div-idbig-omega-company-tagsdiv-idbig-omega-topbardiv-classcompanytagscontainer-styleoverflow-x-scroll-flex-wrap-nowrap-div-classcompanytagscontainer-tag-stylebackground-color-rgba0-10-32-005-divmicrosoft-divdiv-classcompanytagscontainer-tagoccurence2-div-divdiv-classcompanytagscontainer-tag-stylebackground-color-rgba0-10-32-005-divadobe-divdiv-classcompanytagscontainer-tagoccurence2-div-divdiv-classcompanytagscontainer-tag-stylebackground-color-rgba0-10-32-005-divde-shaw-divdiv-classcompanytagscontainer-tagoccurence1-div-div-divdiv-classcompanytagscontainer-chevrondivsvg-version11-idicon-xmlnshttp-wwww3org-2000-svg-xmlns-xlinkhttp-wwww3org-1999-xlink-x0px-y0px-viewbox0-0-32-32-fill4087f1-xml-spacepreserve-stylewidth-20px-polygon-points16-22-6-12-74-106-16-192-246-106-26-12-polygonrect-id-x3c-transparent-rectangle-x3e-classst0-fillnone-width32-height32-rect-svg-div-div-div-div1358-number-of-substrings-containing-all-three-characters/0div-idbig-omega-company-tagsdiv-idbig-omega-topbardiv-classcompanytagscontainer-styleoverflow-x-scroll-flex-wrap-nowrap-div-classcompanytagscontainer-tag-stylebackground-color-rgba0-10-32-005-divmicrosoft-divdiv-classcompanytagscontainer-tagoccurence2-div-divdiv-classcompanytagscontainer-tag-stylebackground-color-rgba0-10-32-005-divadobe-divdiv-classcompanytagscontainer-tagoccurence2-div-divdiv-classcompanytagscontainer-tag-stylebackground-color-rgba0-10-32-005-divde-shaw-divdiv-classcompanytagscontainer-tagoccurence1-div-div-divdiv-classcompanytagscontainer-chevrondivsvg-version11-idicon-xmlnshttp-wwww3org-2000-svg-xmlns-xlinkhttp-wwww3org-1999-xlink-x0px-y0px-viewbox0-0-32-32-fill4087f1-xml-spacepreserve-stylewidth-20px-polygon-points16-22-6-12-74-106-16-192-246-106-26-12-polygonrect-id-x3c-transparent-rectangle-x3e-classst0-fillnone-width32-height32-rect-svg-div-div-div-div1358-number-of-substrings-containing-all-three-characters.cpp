class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int cnt[3] = {0};
        int i = 0;
        for(int j=0; j<s.size(); ++j){
            cnt[s[j]-'a']++;

            while(cnt[0] and cnt[1] and cnt[2]){
                cnt[s[i++]-'a']--; 
            }
            ans += i;
        }
        return ans;
        
    }
};