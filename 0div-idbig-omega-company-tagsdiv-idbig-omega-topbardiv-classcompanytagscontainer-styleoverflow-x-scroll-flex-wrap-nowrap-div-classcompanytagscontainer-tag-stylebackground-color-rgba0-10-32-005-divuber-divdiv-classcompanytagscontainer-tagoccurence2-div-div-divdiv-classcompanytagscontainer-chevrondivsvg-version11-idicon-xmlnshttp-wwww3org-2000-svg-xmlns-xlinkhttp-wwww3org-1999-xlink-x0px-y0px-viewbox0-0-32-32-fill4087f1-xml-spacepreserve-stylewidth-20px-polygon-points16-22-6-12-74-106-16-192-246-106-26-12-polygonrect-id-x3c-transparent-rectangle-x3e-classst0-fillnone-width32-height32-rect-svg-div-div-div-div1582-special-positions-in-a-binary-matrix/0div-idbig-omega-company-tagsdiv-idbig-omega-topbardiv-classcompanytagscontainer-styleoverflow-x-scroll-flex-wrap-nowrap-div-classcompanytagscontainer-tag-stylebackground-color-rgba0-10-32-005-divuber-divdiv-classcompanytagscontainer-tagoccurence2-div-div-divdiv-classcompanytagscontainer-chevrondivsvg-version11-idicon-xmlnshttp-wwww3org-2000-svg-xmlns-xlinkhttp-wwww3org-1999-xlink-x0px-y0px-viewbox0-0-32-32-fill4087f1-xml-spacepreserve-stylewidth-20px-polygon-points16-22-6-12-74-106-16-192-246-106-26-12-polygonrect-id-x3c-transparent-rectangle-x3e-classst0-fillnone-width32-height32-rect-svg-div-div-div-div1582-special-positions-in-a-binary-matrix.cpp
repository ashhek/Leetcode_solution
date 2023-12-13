class Solution {
private:
    bool check(int r, int c, vector<vector<int>>&mat){
        int n = mat.size();
        int m = mat[0].size();
        for(int j=0; j<m; ++j){
            if(mat[r][j] != 0 and j!=c) return false;
        }
        for(int i=0; i<n; ++i){
            if(mat[i][c] != 0 and i!=r) return false;
        }
        return true;
    }    
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(mat[i][j]==1){
                    if(check(i, j, mat)) cnt++;
                }
            }
        }
        return cnt;
    }
};