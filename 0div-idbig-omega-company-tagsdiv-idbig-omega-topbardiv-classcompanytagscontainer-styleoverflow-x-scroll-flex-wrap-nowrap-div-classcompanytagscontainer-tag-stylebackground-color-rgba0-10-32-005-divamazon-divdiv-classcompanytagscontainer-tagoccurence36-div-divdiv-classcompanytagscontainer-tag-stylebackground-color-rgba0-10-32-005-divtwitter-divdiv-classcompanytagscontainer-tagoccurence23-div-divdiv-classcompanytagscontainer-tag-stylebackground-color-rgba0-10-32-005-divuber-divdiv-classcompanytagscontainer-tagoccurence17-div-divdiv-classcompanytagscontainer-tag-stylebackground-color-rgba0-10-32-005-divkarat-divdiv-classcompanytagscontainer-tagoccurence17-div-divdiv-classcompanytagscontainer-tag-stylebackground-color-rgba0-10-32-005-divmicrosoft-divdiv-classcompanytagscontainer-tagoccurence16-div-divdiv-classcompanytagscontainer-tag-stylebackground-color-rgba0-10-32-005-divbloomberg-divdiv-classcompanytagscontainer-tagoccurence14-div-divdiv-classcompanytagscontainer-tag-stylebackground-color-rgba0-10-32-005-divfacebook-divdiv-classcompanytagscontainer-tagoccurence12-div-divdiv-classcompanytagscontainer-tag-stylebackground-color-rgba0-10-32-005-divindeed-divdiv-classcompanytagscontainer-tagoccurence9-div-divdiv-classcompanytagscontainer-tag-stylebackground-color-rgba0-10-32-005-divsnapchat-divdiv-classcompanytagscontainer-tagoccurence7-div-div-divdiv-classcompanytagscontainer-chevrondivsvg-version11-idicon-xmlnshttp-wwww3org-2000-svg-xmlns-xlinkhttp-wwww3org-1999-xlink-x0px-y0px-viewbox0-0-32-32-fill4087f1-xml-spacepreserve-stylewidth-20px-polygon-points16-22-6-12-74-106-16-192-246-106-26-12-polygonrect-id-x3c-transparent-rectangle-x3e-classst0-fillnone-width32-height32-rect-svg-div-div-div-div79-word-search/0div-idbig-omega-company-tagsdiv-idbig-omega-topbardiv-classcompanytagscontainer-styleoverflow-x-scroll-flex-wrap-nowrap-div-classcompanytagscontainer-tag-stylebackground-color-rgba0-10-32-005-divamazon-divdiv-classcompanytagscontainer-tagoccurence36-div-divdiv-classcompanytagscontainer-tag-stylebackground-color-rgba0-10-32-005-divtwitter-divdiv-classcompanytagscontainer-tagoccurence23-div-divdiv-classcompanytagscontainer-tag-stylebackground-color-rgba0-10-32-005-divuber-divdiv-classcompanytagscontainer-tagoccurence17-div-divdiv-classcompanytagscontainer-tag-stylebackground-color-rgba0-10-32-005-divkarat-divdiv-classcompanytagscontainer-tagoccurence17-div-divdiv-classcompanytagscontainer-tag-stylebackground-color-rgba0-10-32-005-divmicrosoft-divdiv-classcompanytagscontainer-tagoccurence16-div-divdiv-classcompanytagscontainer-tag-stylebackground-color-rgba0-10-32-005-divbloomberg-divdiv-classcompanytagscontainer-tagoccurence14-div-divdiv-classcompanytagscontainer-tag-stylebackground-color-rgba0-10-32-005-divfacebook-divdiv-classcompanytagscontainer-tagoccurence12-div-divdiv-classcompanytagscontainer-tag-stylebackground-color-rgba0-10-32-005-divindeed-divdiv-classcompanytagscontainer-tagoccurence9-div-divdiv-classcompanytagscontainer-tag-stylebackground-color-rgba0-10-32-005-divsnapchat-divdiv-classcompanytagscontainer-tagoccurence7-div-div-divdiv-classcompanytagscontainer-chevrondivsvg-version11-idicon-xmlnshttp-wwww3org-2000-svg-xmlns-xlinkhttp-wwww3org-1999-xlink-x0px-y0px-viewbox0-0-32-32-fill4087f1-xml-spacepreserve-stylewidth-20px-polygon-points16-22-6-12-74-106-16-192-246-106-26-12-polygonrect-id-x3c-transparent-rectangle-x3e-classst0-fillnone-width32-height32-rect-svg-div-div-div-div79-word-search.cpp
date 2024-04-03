class Solution {
public:
    int n;
    int m;
    bool find(vector<vector<char>>& board, string& word, int i, int j,
              int ind) {
        if (ind == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '$')
            return false;

        if (board[i][j] != word[ind])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';
        int dir[] = {0, 1, 0, -1, 0};

        for (int k = 0; k < 4; ++k) {
            int nrow = i + dir[k];
            int ncol = j + dir[k + 1];

            if (find(board, word, nrow, ncol, ind + 1))
                return true;
        }
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] and find(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};