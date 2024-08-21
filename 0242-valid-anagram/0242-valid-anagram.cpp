class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(256, 0);
        for(char& ch : s) {
            count[ch-'0']++;
        }
        for(char& ch : t) {
            count[ch-'0']--;
        }
        for(int& ch : count) {
            if(ch!=0) return false;
        }
        return true;
    }
};