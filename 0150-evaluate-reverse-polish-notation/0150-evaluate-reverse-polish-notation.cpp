class Solution {
    long long operation(int x, int y, string sign) {
        if(sign=="+") return x+y;
        if(sign=="-") return x-y;
        if(sign=="*") return x*y;
        else return x/y;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(string tk : tokens) {
            if(tk=="+" || tk=="-" || tk=="*" || tk=="/") {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();

                int res = operation(x, y, tk);
                st.push(res);
            }
            else {
                int r = stoi(tk);
                st.push(r);
            }
        }
        return st.top();
    }
};