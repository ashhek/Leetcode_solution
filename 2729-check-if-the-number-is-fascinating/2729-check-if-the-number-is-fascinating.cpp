class Solution {
public:
    bool isFascinating(int n) {
    string s = to_string(n) + to_string(n*2) + to_string(n*3);
    unordered_set<char> st(s.begin(), s.end());
    return (st.size() == 9 && s.size() == 9 && st.find('0') == st.end() );

    }
};