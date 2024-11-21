class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dir[] = {0, -1, 0, 1, 0};
        int n = board.size(), m = board[0].size();

        int rook_x = -1;
        int rook_y = -1;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'R') {
                    rook_x = i;
                    rook_y = j;
                    break;
                }
            }
        }
        int count = 0;
        for (int k = 0; k < 4; ++k) {
            int x = rook_x; int y = rook_y;
            while (true) {
                x += dir[k];
                y += dir[k+1];

                if(x < 0 || x >= n || y < 0 || y >=m || board[x][y] == 'B') {
                    break;
                }
                if(board[x][y] == 'p') {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};