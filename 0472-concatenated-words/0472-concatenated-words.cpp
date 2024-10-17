class Solution {
    unordered_map<int, bool> mp;  // Use index as key for memoization
    bool isOk(int i, string &s, unordered_set<string>& st) {
        if (i == s.size()) return true;

        if (mp.find(i) != mp.end()) return mp[i];  // Memoize based on index

        bool found = false;
        for (int j = i; j < s.size(); ++j) {
            string temp = s.substr(i, j - i + 1);
            if (st.find(temp) != st.end()) {
                found |= isOk(j + 1, s, st);
                if (found) break;  // Early exit if we found a valid combination
            }
        }
        return mp[i] = found;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        unordered_set<string> st(words.begin(), words.end());
        int minSize = INT_MAX;

        for (string word : words) {
            int sz = word.size();
            minSize = min(minSize, sz);
        }

        vector<string> res;
        for (string word : words) {
            if (word.size() == minSize) continue;
            st.erase(word);  // Temporarily remove word to avoid matching itself
            mp.clear();  // Clear memoization map for each new word
            if (isOk(0, word, st)) {
                res.push_back(word);
            }
            st.insert(word);  // Reinsert word after checking
        }
        return res;
    }
};
