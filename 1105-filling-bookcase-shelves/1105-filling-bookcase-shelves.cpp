class Solution {
    int n;
    int width;
    int dp[1001][1001];

    int help(int i, vector<vector<int>>& books, int remainingWidth, int maxHeight){
        if(i>=n) return maxHeight;

         if(dp[i][remainingWidth] != -1) return dp[i][remainingWidth];

        int wd = books[i][0];
        int ht = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;


        if(remainingWidth >= wd){
            keep = help(i+1, books, remainingWidth - wd, max(maxHeight, ht));
        }

        skip = maxHeight + help(i+1, books, width-wd, ht);

        return dp[i][remainingWidth] = min(skip, keep);
    }


public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        width = shelfWidth;

        memset(dp, -1, sizeof(dp));

        int remainingWidth = shelfWidth;
        return help(0, books, remainingWidth, 0);

    }
};