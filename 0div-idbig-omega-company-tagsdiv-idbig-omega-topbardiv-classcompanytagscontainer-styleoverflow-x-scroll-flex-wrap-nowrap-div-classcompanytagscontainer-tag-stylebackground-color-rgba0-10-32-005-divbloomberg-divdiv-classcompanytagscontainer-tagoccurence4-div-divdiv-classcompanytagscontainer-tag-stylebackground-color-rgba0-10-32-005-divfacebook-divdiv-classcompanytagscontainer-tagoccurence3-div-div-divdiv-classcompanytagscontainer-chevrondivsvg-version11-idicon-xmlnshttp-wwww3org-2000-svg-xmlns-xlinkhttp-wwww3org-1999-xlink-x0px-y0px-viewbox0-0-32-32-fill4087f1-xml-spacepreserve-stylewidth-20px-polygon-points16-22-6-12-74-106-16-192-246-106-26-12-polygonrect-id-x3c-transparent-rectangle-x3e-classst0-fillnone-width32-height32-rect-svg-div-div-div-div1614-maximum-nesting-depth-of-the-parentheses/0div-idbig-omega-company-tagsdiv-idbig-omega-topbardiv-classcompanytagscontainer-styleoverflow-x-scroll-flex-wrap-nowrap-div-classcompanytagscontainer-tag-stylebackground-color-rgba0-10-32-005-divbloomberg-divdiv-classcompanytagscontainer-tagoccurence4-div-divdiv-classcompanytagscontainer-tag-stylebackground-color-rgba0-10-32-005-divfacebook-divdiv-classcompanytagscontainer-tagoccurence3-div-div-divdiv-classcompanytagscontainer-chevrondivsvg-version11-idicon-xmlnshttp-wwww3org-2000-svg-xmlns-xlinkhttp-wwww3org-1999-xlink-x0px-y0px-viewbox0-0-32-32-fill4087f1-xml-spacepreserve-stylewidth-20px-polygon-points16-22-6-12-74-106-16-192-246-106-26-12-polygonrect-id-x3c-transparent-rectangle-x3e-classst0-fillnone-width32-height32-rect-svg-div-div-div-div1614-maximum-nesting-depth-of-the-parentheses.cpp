class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        stack<int> st;
        int ans = 0;
        for (char& ch : s) {

            if (ch == '(')
                st.push(ch);

            int n = st.size();
            ans = max(ans, n);

            if (ch == ')' and !st.empty()) {
                st.pop();
            }
        }
        return ans;
    }
};