class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int n = columnNumber;
        while(n!=0){
            ans.push_back('A' + (n-1)%26);
            n = (n-1)/26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};