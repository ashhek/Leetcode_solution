class Solution {
private:
    bool isOk(int i, int j, vector<vector<int>>&count) {
        for(int k=0; k<26; ++k) {
            if(count[i][k] && count[j][k]) {
                return false;
            }
        }
        return true;
    }    
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>count(n, vector<int>(26, 0));
        int prod = 0;
        for(int i=0; i<n; ++i) {
            string s = words[i];
            for(char& ch : s) {
                count[i][ch-'a']++;
            }
        }

        for(int i = 0; i < words.size(); ++i) {
            for(int j=i+1; j< words.size(); ++j) {
                string s = words[i];
                string t = words[j];

                if(isOk(i, j, count)) {
                    int n = s.size(), m = t.size();
                    prod = max(prod, n*m);
                }
            }
        }
        return prod;
    }
};