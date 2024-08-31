class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];

        int ind = 0;
        for(auto edge : edges) {
            adj[edge[0]].push_back({edge[1], succProb[ind]});
            adj[edge[1]].push_back({edge[0], succProb[ind]});
            ind++;
        }
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start_node});

        vector<double>prob(n, 0);
        prob[start_node] = 1;

        while(!pq.empty()) {
            double curr_prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto child : adj[node]) {
                int adjNode = child.first;
                double adj_prob = child.second;

                if(curr_prob * adj_prob > prob[adjNode]) {
                    prob[adjNode] = curr_prob * adj_prob;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }
        return prob[end_node];
    }
};