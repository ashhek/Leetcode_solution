class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string t = s;
        reverse(s.begin(),s.end());
        if(t==s) return true;
        return false;
    }
};