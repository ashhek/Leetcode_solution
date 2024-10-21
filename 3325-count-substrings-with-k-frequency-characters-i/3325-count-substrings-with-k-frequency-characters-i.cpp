class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;

        for(int i=0; i<s.size(); ++i) {
            vector<int>mp(26, 0);
            string t = "";
            for(int j=i; j<s.size(); ++j) {
                t += s[j];
                mp[s[j] - 'a']++;

                //cout << t << endl;

                int cnt = 0;
                for(int ind=0; ind<26; ++ind) {
                    if(mp[ind]>=k) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};