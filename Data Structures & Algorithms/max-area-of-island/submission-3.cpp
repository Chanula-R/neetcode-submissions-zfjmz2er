class Solution {
public:
    int dfs(int r,int c, vector<vector<int>>& grid)
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] == 0)
        {
            return 0;
        }

        grid[r][c] = 0;        
        return dfs(r-1,c,grid) + dfs(r+1,c,grid) + dfs(r,c-1,grid) + dfs(r,c+1,grid) + 1;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxA = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for (int r=0; r<ROWS ; r++)
        {
            for (int c=0; c<COLS ; c++)
            {
                int count = 0;
                int A = dfs(r,c,grid);
                if (A > maxA)
                {
                    maxA = A;
                }
            }
        }
        return maxA;
        
    }
};
