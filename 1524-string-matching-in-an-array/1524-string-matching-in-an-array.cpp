class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        unordered_set<string> res;
        for (int i = 0; i < n; ++i) {
            string s = words[i];
            for (int j = 0; j < n; ++j) {
                if (j == i)
                    continue;
                string t = words[j];
                int ind = t.find(s);
                if (ind != -1)
                    res.insert(s);
                    //break;
            }
        }
        vector<string>ans(res.begin(), res.end());
        return ans;
    }
};