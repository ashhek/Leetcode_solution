class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;
        int minCount = 0;

        for(int i=0; i<s.size(); ++i){
                if(s[i]=='b') countB++;
                else minCount = min(minCount+1, countB);
        }
        return minCount;
    }
};