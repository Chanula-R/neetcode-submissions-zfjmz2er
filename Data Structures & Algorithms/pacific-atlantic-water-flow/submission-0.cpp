class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        set<pair<int,int>>alt;
        set<pair<int,int>>pac;

        int ROWS = heights.size();
        int COLS = heights[0].size();

        for (int c = 0; c < COLS ; c++)
        {
            dfs(0,c,pac,heights[0][c],heights);
            dfs(ROWS-1,c,alt,heights[ROWS-1][c],heights);
        }

        for (int r = 0 ; r < ROWS ; r++)
        {
            dfs(r,0,pac,heights[r][0],heights);
            dfs(r,COLS-1,alt,heights[r][COLS-1],heights);
        }

        for (pair<int,int> a : alt)
        {
            for (pair<int,int> p : pac)
            {
                if (p == a)
                {
                    res.push_back({p.first,p.second});
                }
            }
        }
        return res;
    }

    void dfs(int r,int c,set<pair<int,int>>& visit,int prevHeight,vector<vector<int>>& heights)
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||visit.count({r,c})||heights[r][c] < prevHeight)
        {
            return;
        }

        visit.insert({r,c});

        dfs(r-1,c,visit,heights[r][c],heights);
        dfs(r,c+1,visit,heights[r][c],heights);
        dfs(r+1,c,visit,heights[r][c],heights);
        dfs(r,c-1,visit,heights[r][c],heights);
    }
};
