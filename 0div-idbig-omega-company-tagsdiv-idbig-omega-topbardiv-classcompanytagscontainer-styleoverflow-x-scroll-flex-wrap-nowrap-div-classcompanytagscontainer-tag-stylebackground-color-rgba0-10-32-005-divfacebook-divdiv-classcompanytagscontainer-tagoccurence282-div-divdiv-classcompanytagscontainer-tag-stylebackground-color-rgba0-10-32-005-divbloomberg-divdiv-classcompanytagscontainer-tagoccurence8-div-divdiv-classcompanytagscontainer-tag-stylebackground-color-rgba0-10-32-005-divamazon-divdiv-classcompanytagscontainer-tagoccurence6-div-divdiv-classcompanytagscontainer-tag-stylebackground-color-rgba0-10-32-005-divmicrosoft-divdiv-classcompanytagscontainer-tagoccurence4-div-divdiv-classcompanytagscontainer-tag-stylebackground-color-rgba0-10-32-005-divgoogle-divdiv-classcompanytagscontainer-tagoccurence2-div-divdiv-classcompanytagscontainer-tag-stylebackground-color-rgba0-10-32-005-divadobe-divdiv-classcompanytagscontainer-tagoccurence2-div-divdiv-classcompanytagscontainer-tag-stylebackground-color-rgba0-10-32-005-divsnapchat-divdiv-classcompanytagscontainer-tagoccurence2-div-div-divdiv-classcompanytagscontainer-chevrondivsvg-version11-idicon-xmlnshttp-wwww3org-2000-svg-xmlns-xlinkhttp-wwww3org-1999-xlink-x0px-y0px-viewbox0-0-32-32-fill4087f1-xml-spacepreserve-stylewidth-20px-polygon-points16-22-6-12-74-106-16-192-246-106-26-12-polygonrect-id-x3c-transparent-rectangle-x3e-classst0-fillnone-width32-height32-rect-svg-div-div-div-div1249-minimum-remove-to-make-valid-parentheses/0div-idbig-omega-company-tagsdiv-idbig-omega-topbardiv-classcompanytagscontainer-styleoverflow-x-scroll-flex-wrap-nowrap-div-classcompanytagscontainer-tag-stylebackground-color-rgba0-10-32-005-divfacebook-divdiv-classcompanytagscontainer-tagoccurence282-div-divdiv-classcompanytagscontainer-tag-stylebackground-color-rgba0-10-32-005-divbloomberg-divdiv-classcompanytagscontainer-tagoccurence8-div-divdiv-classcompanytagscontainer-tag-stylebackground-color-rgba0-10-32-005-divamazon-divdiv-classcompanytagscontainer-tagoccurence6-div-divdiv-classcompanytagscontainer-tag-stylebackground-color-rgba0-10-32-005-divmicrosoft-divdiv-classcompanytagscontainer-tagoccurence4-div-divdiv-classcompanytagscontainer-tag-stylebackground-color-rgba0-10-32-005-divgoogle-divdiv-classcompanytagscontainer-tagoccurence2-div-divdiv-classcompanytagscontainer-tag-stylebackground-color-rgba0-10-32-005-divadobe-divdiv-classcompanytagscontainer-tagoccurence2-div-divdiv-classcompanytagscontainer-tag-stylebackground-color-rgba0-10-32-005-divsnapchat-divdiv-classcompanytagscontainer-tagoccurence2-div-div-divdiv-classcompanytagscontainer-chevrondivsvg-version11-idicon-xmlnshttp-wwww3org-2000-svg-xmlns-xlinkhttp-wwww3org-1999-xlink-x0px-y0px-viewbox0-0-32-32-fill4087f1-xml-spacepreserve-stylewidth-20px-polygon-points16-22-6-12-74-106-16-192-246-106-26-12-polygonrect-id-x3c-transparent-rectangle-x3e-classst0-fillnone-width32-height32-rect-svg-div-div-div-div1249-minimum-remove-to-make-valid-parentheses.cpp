class Solution {
public:
    string minRemoveToMakeValid(string s) {

        string ans;
        stack<char> st;

        for (auto ch : s) {
            if (ch == '(')
                st.push(ch);

            else if (ch == ')') {
                if (st.size()) {
                    st.pop();
                } else {
                    continue;
                }
            }
            ans += ch;
        }
        string res;
        stack<char> st1;
        for (int i = ans.size() - 1; i >= 0; --i) {
            if (ans[i] == ')')
                st1.push(ans[i]);

            else if (ans[i] == '(') {
                if (st1.size()) {
                    st1.pop();
                } else {
                    continue;
                }
            }
            res += ans[i];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};