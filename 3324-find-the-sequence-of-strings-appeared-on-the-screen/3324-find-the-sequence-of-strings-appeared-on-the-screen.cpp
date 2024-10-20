class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;

        string temp = "";
        int ind = 0;
        char ch = 'a';
        while(ch <= 'z') {
            if (ind == target.size())
                break;
            else if (ch == target[ind]) {
                ind++;
                temp += ch;
                res.push_back(temp);
                ch = 'a';
                continue;
            } else {
                temp += ch;
                res.push_back(temp);
                temp.pop_back();
            }
            ch++;
        }
        return res;
    }
};