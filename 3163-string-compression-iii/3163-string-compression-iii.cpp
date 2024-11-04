class Solution {
public:
    string compressedString(string word) {
        string res = "";
        int cnt = 1;

        for(int i=1; i<word.size(); ++i) {
            if(cnt == 9 || word[i] != word[i-1]) {
                res += to_string(cnt);
                res += word[i-1];
                cnt = 1;
            } else {
                cnt++;
            }
        }
        if(cnt != 0) {
            res += to_string(cnt);
            res += word[word.size()-1];
        }
        return res;
    }
};