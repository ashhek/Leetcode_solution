class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        vector<int> adj[n];
        vector<int> indegree(n,0);

        for(auto it:richer){
             adj[it[0]].push_back(it[1]);
             indegree[it[1]]++;
        }
        queue<int>q;
        vector<int> tsort(n);
        for(int i=0; i<n; ++i){
            if(indegree[i]==0)
            q.push(i);
            tsort[i] = i;
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:adj[node]){

                if(quiet[node]<quiet[it]){   
                    quiet[it] = quiet[node]; 
                   tsort[it] = tsort[node];
                }

                indegree[it]--;
                if(indegree[it]==0)   
                q.push(it);
            }
        }
        return tsort;
    }
};