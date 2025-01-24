class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // int n = graph.size();
        // queue<int>q;
        // vector<int>indegree(n);
        // vector<int>adj[n];
        // vector<int>vis(n, 0);
        // for(int i=0; i<n; ++i) {
        //     for(auto v : graph[i]) {
        //         adj[v].push_back(i);
        //         indegree[v]++;
        //     }
        // }
        // for(int i=0; i<n; ++i) {
        //     if(indegree[i] == 0) {
        //         q.push(i);
        //     }
        // }
        // vector<int>res;
        // while(!q.empty()) {
        //     int node = q.front();
        //     q.pop();

        //     res.push_back(node);
        //     vis[node] = 1;

        //     for(auto it : adj[node]) {
        //         if(!vis[it]) {
        //             vis[it] = 1;
        //             q.push(it);
        //         }
        //     }
        // }
        // return res;
        int n = graph.size();
        vector<int>adj[n];
        for(int i=0; i<n; ++i) {
            for(auto it : graph[i]) {
                adj[it].push_back(i);
            }
        }
        vector<int>indegree(n, 0);
        for(int i=0; i<n; ++i) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back(node);

            for(auto child : adj[node]) {
                indegree[child]--;

                if(indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};