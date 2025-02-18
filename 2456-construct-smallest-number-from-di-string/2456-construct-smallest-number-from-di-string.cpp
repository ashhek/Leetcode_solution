class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<char> st;

        for (int i = 0; i <= pattern.size(); i++) {
            st.push('1' + i);
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result.push_back(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};
