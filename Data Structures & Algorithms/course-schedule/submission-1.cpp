class Solution {
public:
    void dfs(int v,vector<vector<int>>& adj,vector<int>& visited,bool& cycle)
    {
        if (visited[v] == 1)
        {
            cycle = true;
            return;
        }
        if (visited[v] == 2)
        {
            return;
        }
        
        visited[v] = 1;
        for (int nb : adj[v])
        {
            dfs(nb,adj,visited,cycle);
            if (cycle) return;
        }
        visited[v] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (const auto& course : prerequisites)
        {            int u = course[0];
            int v = course[1];
            adj[u].push_back(v); 
        }

        bool cycle = false;
        for (int i = 0; i < numCourses ; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i,adj,visited,cycle);
                if (cycle)
                {
                    return false;
                }
            }
        }
        return true; 
    }
};