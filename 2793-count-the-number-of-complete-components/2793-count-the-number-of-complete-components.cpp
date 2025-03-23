class Solution {
public:
    int ans = 0;
    void BFS(vector<int> adj[],vector<int> &vis,int n,int src)
    {
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        int nodecount = 0,edgecount = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            nodecount++;
            for(auto x : adj[node])
            {
                if(vis[x]==0)
                {
                    q.push(x);
                    vis[x] = 1;
                }
                edgecount++;
            }
        }
        if(nodecount*(nodecount-1)==edgecount) ans++;
    }
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i = 0;i<e.size();i++)
        {
        adj[e[i][0]].push_back(e[i][1]);
        adj[e[i][1]].push_back(e[i][0]);
        }
        for(int i = 0;i<n;i++)
        if(vis[i]==0) BFS(adj,vis,n,i);
        return ans;
    }
};