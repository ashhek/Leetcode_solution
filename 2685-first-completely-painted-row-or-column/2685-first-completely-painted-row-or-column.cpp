class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int, int>> rowcol(n*m + 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                rowcol[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(n, 0), col(m, 0);
        for(int i=0; i<arr.size(); i++){
            int r = rowcol[arr[i]].first;
            int c = rowcol[arr[i]].second;
            row[r]++;
            col[c]++;
            if(row[r] == m || col[c] == n) return i; 
        }
        return 0;
    }
};