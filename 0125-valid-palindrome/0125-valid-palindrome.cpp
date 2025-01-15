class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;

        while(i < j) {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
