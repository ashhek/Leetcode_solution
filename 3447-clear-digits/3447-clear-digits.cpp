class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        stack<char> st;
        for(auto i: s){
            if(i>='0' and i<='9') {
                if(st.size()>0) st.pop();
            } else st.push(i);
        }
        while(st.empty()==false){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};