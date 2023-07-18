class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size()-1, col = matrix[0].size()-1;
        help(matrix, ans, row, col, 0, 0);
        return ans;
    }
    void help(vector<vector<int>> & matrix, vector<int> &ans, int er, int ec, int sr, int sc){
        
        for(int j=sc; j<=ec; j++)
        ans.push_back(matrix[sr][j]);
        ++sr;

         if(sc>ec || sr>er) return;

        for(int i=sr; i<=er; i++)
        ans.push_back(matrix[i][ec]);
        --ec;

         if(sc>ec || sr>er) return;

        for(int j=ec; j>=sc ; --j)
        ans.push_back(matrix[er][j]);
        --er;

        if(sc>ec || sr>er) return;

        for(int i=er; i>=sr; --i)
        ans.push_back(matrix[i][sc]);
        ++sc;

         if(sc>ec || sr>er) return;

        help(matrix, ans, er, ec, sr, sc);

    }
};