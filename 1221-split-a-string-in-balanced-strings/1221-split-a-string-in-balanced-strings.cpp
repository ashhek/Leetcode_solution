class Solution {
public:
    int balancedStringSplit(string s) {
        int r {},l {},result {};
        for(char i : s){
            r += i=='R' ? 1 : 0; // Add 1 if the char is R
            l += i=='L' ? 1 : 0; // Add 1 if the char is L
            result += r==l ? 1 : 0; // If both r == l , add 1 to result
        }
        return result;
    }
};