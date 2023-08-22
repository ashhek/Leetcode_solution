class Solution {
public:
    string convertToTitle(int n) {
        string ans = "";

        while(n>0){
            n--;
            int curr = (n)%26;
            ans += curr + 'A';
            n = n/26;      
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};