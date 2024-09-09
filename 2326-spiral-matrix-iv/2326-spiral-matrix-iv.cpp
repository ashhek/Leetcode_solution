class Solution {
    void help(ListNode* head, vector<vector<int>>& res, int sr, int sc, int er, int ec) {
       // if (sr > er || sc > ec || !head) return; // Base case to stop recursion
        
        for (int i = sc; i <= ec; ++i) {
            if (!head) return;
            res[sr][i] = head->val;
            head = head->next;
        }
        sr++; 
        if(sr > er) return;
    
        for (int i = sr; i <= er; ++i) {
            if (!head) return;
            res[i][ec] = head->val;
            head = head->next;
        }
        ec--; 
        if(ec < sc) return;
            for (int i = ec; i >= sc; --i) {
                if (!head) return;
                res[er][i] = head->val;
                head = head->next;
            }
            er--; 
        if(er < sr) return;
        
            for (int i = er; i >= sr; --i) {
                if (!head) return;
                res[i][sc] = head->val;
                head = head->next;
            }
            sc++; 
        if(sc > ec) return;
    
        help(head, res, sr, sc, er, ec);
    }
    
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1)); // Initialize the result matrix with -1
        help(head, res, 0, 0, m - 1, n - 1); // Start the recursion
        return res;
    }
};
