class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<string,int>mp;

        for(int i=0; i<n; ++i) {
            int first = matrix[i][0];
            string s = "";
            for(int j=0; j<m; ++j) {
                if(matrix[i][j] == first) {
                    s += 'o';
                } else {
                    s += 'z';
                }
            }
            mp[s]++;
        }
        int maxEqualRow = 0;
        for(auto& it : mp) {
            maxEqualRow = max(maxEqualRow, it.second);
        }
        return maxEqualRow;
    }
};