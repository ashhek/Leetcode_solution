
class Solution {
public:
    set<string> st;

    bool check(string &s) {
        // Check for parent folders by removing each level in reverse
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '/' && st.find(s.substr(0, i)) != st.end()) {
                return true; // Found a parent folder
            }
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        st.clear();
        
        // Sort folders by length to ensure parent folders come before subfolders
        sort(folder.begin(), folder.end());
        
        for ( string &s : folder) {
            if (!check(s)) {
                st.insert(s);  // Add only non-subfolder paths
            }
        }

        // Prepare the final list from the set of unique non-subfolder paths
        return vector<string>(st.begin(), st.end());
    }
};
