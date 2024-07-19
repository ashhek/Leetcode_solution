class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        set<int>st;
        vector<int>v;

        for(int i=0; i<matrix.size(); ++i){
            int mx = INT_MAX;
            int col = -1;
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j] < mx){
                    mx = matrix[i][j];
                    col = j;
                }
            }
            int mn = INT_MIN;
            for(int k=0; k<matrix.size(); ++k){
                if(matrix[k][col] > mn){
                    mn = matrix[k][col];
                }
            }
            if(mx==mn) v.push_back(mx);
        }
        return v;
    }
};