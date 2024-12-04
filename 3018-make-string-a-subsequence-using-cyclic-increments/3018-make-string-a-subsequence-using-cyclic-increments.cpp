class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(); int m = str2.size();
        int i = 0; int j = 0;
        while(i < n) {
            if(j == str2.size()) {
                return true;
            }
            int x = str1[i] - 'a';
            int y = str2[j] - 'a';
           // cout << y << endl;
            if(x == 25 && y != 25) x = 0;
            if(y - x == 1 || y - x == 0) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if(j == str2.size()) return true;
        return false;
    }
};