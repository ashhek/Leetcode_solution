class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string t;

        long long sum = 0;
        for(char ch : s) {
            if(ch != '0'){
                t += ch;
            }
            sum += (ch - '0');
        }
        long long x = 0;
        if(!t.empty())
             x = stoll(t);
        return x * sum;
    }
};