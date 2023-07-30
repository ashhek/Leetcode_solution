class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        string ans;

        if(n>=m){
            for(int i=0; i<n; ++i){
                ans.push_back(word1[i]);
                if(m>0){
                    ans.push_back(word2[i]);
                    m--;
                }
            }
        }
            else{
                for(int i=0; i<m; ++i){
                if(n>0){
                    ans.push_back(word1[i]);
                    n--;
                }
                ans.push_back(word2[i]);
            }
        }
        return ans;
    }
};