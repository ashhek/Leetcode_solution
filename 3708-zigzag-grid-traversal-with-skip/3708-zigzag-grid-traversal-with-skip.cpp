class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int>res;
        int flip=0;

        int n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; ++i) {
            stack<int>st;
            for(int j=0; j<m; ++j) {
                if(flip%2 == 0) {
                    if(j%2 == 0) 
                    res.push_back(grid[i][j]);
                } else {
                    if(j&1)
                    st.push(grid[i][j]);
                }
            }
            flip ^= 1;
            while(!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};