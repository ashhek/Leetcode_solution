class Solution {
public:
    int titleToNumber(string c) {
        int ans=0;
        int j=0;
    for(int i=c.size()-1;i>=0;i--)  ans+=(c[i]-'A'+1)*pow(26,j++);      
         return ans;
    }
};