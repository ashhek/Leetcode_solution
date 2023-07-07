class Solution {
public:
    bool check(string s, int i, int j){
         while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
         }
            return true;
    }

    
    bool validPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n-1;
        bool found = true;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                if(n==3) return false;
                return check(s, i+1, j) || check(s, i, j-1);
            }
        }
        return true;
    }
};