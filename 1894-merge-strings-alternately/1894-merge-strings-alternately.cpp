class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size() + word2.size();
        string res(n, '.');

        int i=0; int j=0;
        int idx = 0;

        while(i < word1.size() && j < word2.size()) {
            if(idx&1) {
                res[idx] = word2[j];
                j++; idx++;
            } else {
                res[idx] = word1[i];
                i++; idx++;
            }
        }
        while(i < word1.size()) {
            res[idx++] = word1[i++];
        }
        while(j < word2.size()) {
            res[idx++] = word2[j++];
        }
        return res;
    }
};