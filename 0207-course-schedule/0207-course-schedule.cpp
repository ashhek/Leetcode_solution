class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];

        for(auto pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int>indegree(n, 0);
        for(int i=0; i<n; ++i) {
            for(auto child : adj[i]) {
                indegree[child]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; ++i) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(auto child : adj[node]){
                indegree[child]--;
                if(indegree[child]==0) {
                    q.push(child);
                }
            }
        }
        return cnt==n;
    }
};