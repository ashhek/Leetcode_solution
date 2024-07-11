class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> p(n);
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                p[i] = j;
                p[j] = i;
            }
        }
        string res;
        int dir = 1;
        for (int i = 0; i < s.size(); i+=dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = p[i];
                dir = -dir;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};