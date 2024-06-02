class Solution {
private:
    bool isSafe(int row, int col, vector<string>&board){
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col>=0){
            if(board[row--][col--]=='Q')
            return false;
        }

        row = duprow;
        col = dupcol;

         while(col>=0){
            if(board[row][col--]=='Q')
            return false;
        }

        row = duprow;
        col = dupcol;

        while(row<board.size() && col>=0){
            if(board[row++][col--]=='Q')
            return false;
        }

        return true;

    }    
    
private:
    void help(int col, vector<string>&board, vector<vector<string>>&ans){
        if(col==board.size()){
            ans.push_back(board);
            return;
        }

        for(int row=0; row<board.size(); ++row){
            if(isSafe(row, col, board)){
                board[row][col] = 'Q';
                help(col+1, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0; i<n; ++i){
            board[i] = s;
        }
        help(0, board, ans);
        return ans;
    }
};