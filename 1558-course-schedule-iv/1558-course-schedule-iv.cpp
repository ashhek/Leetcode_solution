class Solution {
    bool bfs(vector<vector<int>>&adj, int src, int dest, int n) {
        queue<int>q;
        vector<int>vis(n+1, 0);
        q.push(src);
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            vis[node] = 1;
            if(node == dest) return true;

            for(auto child : adj[node]) {
                if(!vis[child]) {
                    q.push(child);
                }
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>>adj(n);

        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>res;
        for(auto it : queries) {
            if(bfs(adj, it[0], it[1], n))
            res.push_back(true);
            else
            res.push_back(false);
        }
        return res;
    }
};