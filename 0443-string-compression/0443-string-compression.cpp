class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> res;
        int len = 1;

        for (int i = 1; i < n; ++i) {
            if (chars[i] == chars[i - 1]) {
                len++;
            } else {
                res.push_back(chars[i - 1]);
                if (len == 1)
                    continue;

                string sz = to_string(len);
                for (char& ch : sz) {
                    res.push_back(ch);
                }
                len = 1;
            }
        }
        res.push_back(chars[n - 1]);
        if (len > 1) {
            string sz = to_string(len);
            for (char& ch : sz) {
                res.push_back(ch);
            }
        }
        chars = res;
        return res.size();
    }
};