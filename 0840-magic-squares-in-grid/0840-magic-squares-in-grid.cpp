class Solution {
public:
    bool isMagicSquare(vector<vector<int>>&grid,int i,int j)
    {
        // Check if numbers in square within the range [1,9]
        for(int row = i ; row <= i+2 ;row++)
        {
            for(int col = j ; col <= j+2 ;col++)
            {
                if(grid[row][col] < 1 || grid[row][col] > 9)
                {
                    return false;
                }
            }
        }

        // Check if numbers in square are distinct
        vector<bool>distinct(9,false);
        for(int row = i ; row <= i+2 ;row++)
        {
            for(int col = j ; col <= j+2 ;col++)
            {
                int num=grid[row][col];
                if(distinct[num - 1])
                {
                    return false;
                }
                distinct[num - 1] = true;
            }
        }

        // Calculate sums of rows, columns, and diagonals
        int row1=grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int row2=grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int row3=grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        int col1=grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int col2=grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int col3=grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

        int dia1=grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int dia2=grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        if(row1 == row2 && row2 == row3 && row3 == col1 && col1 == col2 && col2 == dia1 && dia1 == dia2)
        {
            return true;
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int rows=grid.size();
        int cols=grid[0].size();

        for(int i=0;i<rows-2;i++)
        {
            for(int j=0;j<cols-2;j++)
            {
                if(isMagicSquare(grid,i,j))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};