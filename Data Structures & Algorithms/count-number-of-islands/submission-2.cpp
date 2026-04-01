class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
        {
            return;
        }
        if (grid[r][c] == '1')
        {
            grid[r][c] = '0';
            dfs(r+1,c,grid);
            dfs(r,c-1,grid);
            dfs(r,c+1,grid);
            dfs(r-1,c,grid);  
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int count = 0;
        for (int i = 0; i < ROWS ; i++)
        {
            for (int j = 0; j < COLS ; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};
