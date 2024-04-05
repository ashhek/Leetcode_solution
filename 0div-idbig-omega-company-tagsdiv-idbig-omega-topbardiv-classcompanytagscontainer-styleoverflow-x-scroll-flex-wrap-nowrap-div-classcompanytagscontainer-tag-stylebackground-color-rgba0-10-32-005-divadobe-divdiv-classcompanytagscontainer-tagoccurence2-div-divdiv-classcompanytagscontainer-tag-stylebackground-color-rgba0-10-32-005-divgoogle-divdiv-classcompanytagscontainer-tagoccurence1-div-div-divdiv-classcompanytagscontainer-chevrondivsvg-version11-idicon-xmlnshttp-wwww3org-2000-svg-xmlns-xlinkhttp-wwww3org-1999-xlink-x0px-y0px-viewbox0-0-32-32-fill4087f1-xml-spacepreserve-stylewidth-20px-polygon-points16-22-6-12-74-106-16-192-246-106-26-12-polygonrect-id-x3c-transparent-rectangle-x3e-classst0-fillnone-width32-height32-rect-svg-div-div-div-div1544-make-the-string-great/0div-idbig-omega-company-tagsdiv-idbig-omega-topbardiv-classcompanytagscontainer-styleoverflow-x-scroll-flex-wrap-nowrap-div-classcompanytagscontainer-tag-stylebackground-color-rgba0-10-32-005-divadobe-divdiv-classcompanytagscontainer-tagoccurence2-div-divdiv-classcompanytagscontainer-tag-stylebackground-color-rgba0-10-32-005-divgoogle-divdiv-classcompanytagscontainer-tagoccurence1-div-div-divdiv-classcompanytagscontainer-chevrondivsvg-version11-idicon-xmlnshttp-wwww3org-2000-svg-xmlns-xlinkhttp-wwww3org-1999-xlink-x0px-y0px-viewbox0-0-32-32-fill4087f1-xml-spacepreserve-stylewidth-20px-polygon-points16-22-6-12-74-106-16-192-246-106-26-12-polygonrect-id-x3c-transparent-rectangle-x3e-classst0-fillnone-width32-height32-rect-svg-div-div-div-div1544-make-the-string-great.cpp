class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char ch : s) {

            if (ans.size() and (ans.back() ^ (1 << 5)) == ch)
                ans.pop_back();

            else
                ans.push_back(ch);
        }
        return ans;
    }
};