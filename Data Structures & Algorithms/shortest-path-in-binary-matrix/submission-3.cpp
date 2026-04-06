class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int length = 1;
        vector<vector<int>> visit(ROWS,vector<int>(COLS));
        queue<pair<int,int>> q;
        visit[0][0] = 1;
        q.push(pair<int,int>(0,0));

        if (grid[ROWS-1][COLS-1] == 1 || grid[0][0] == 1)
        {
            return -1;
        }

        while(!q.empty())
        {
            length++;
            int qLength = q.size();
            for (int i = 0; i < qLength ; i++ )
            {
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                if (r == ROWS-1 && c == COLS -1)
                {
                    return length;
                }

                vector<vector<int>> neighbours = {{r-1,c},{r+1,c},{r,c-1},{r,c+1},
                                                {r-1,c-1},{r-1,c+1},{r+1,c-1},{r+1,c+1}};
                for (int j=0; j<8 ;j++)
                {
                    int nr = neighbours[j][0];
                    int nc = neighbours[j][1];
                    
                    if (min(nr,nc) < 0 || nr >= ROWS || nc >= COLS || visit[nr][nc] || grid[nr][nc])
                    {
                        continue;
                    }
                    if (nr == ROWS-1 && nc == COLS-1)
                    {
                        return length;
                    }
                    q.push(pair<int,int>(nr,nc));
                    visit[nr][nc] = 1;
                    
                }                    
            }
        }
        return -1;   
    }
};