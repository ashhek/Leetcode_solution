class Solution {
    vector<string>res;
    void help(int n, string temp, char prev) {
        if(n == 0) {
            res.push_back(temp);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ++ch) {
            if(prev != ch || prev == '*') {
                temp.push_back(ch);
                help(n-1, temp, ch);
                temp.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        help(n, "", '*');
        if(res.size() < k) return "";
        return res[k-1];
    }
};