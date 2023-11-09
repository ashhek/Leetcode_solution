class Solution {
public:
    int countHomogenous(string s) {
        int i=0,j=0;
        long ans=0;
        while(j<s.size())
        {
           ans+=j-i+1;
           if(s[j]!=s[j+1])
           {
               j++;
               i=j;
               continue;
           }
            j++;
        }
        return ans%1000000007;
    }
};