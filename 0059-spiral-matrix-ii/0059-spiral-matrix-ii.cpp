class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int srow = 0, erow = n-1, scol = 0, ecol = n-1, element = 1, total = n*n;
        while(element <= total)    {
            // step-1 : starting row
            for(int i=scol; i<=ecol && element<=total; i++)   {
                ans[srow][i] = element++;
            }
            srow++;

            // step-2 : ending column
            for(int i=srow; i<=erow && element<=total; i++)   {
                ans[i][ecol] = element++;
            }
            ecol--;

            // step-3 : ending row
            for(int i=ecol; i>=scol && element<=total; i--)   {
                ans[erow][i] = element++;
            }
            erow--;

            // step-4 : starting column
            for(int i=erow; i>=srow && element<=total; i--)   {
                ans[i][scol] = element++;
            }
            scol++;
        }

        return ans;
    }
};