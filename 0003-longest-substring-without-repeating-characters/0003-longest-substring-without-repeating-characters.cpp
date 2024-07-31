class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int i = 0;
        unordered_map<char,int>mp;

        for(int j=0; j<s.size(); ++j){
            mp[s[j]]++;

            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
        }
        return len;
    }
};