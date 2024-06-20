class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,vector<double>& succProb, int start_node,int end_node) {
        vector<pair<int, double>> adj[n];
        int i = 0;
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], succProb[i]});
            adj[it[1]].push_back({it[0], succProb[i]});
            i++;
        }
        vector<double> probs(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        probs[start_node] = 1;

        while (!pq.empty()) {
            double curr_prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto child : adj[node]) {
                double pr = child.second;
                int adjNode = child.first;

                if (pr * curr_prob > probs[adjNode]) {
                    probs[adjNode] = pr * curr_prob;
                    pq.push({probs[adjNode], adjNode});
                }
            }
        }
        return probs[end_node];
    }
};