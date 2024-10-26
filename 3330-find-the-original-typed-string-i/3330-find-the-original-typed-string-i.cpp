class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;

        int cnt = 0;
        for(int i=1; i<word.size(); ++i) {
            if(word[i] == word[i-1]) {
                cnt++;
            } else {
                if(cnt >= 1) ans += cnt;
                cnt = 0;
            }
        }
        if(cnt >= 1) ans += cnt;
        return ans;
    }
};