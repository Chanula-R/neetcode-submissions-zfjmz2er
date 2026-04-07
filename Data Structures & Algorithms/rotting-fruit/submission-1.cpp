class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size(); int COLS = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        for (int i = 0; i < ROWS ; i++)
        {
            for (int j= 0; j < COLS ; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(pair<int,int>(i,j));
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }

            }
        }

        int time = 0;

        while (!q.empty())
        {
            int qLength = q.size();
            for (int i = 0; i < qLength ; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                vector<vector<int>> neighbours = {{r-1,c},{r+1,c},{r,c-1},{r,c+1}};
                for (int j = 0 ; j < 4 ; j++)
                {
                    int nr = neighbours[j][0]; int nc = neighbours[j][1];
                    if (min(nr,nc) < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] == 0 || grid[nr][nc] == 2)
                    {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push(pair<int,int>(nr,nc));
                }
            }
            time++;
        }
        if (!fresh)
        {
            return max(0,time-1);
        }
        else
        {
            return -1;
        }
        
    }
};
