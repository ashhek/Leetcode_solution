class Solution {
public:
    bool isPalindrome(string& s) {
        int i = 0;
        int j = s.size() - 1;

        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void partition(int i, string& s, vector<string> temp,
                   vector<vector<string>>& ans) {
        if (i == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int j = i; j < s.size(); ++j) {
            string t = s.substr(i, j - i + 1);
            if (isPalindrome(t)) {
                temp.push_back(t);
                partition(j + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> temp;
        vector<vector<string>> ans;

        partition(0, s, temp, ans);
        return ans;
    }
};