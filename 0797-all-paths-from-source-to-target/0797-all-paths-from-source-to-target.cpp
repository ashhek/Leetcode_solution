class Solution {
private:
    void dfs(int node, vector<vector<int>>&graph,  vector<vector<int>>&ans,
    vector<int>temp){
        if(node==graph.size()-1){
            temp.push_back(node);
            ans.push_back(temp);
            return;
        }
        

        for(auto child : graph[node]){
           
                temp.push_back(node);
                dfs(child, graph, ans, temp);
                temp.pop_back();
         
        }
    }
        
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n = graph.size();

        vector<int>vis(n, 0);
        vector<int>temp;

        dfs(0, graph, ans, temp);
        return ans;
    }
};