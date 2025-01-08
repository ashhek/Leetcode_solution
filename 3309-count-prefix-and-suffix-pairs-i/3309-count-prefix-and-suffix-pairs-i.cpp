class Solution {
    bool isPrefixandSuffix(string s, string t) {
        if (t.find(s) != 0) return false; 
        reverse(t.begin(), t.end());
        reverse(s.begin(), s.end());
        if (t.find(s) != 0) return false; 
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for(int i=0; i<n; ++i) {
            string s = words[i];
            for(int j=i+1; j<n; ++j) {
                string t = words[j];
                if(isPrefixandSuffix(s, t)) {
                    cnt++;
                }

            }
        }
        return cnt;
    }
};