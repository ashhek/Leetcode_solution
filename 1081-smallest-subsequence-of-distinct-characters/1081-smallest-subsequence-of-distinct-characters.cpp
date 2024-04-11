class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<bool>seen(26, false);
        vector<int>lastIndex(26);

        for(int i=0; i<n; ++i){
            lastIndex[s[i]-'a'] = i;
        }

        string ans;
        for(int i=0; i<n; ++i){
            int ind = s[i] - 'a';

            if(seen[ind] == true) continue;
            while(ans.size()>0 && ans.back()>s[i] and lastIndex[ans.back()-'a']>i){
                seen[ans.back()-'a'] = false;
                ans.pop_back();
            }

            seen[ind] = true;
            ans.push_back(s[i]);

        }
        return ans;
    }
};