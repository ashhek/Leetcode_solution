//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int par[1001];
	int siz[1001];
	
	void init(int n){
	    for(int i=0; i<n; ++i)
	    par[i] = i, siz[i] = 1;
	}
	int findP(int a){
	    if(par[a]==a) return a;
	    return par[a] = findP(par[a]);
	}
	void merge(int a, int b){
	    a = findP(a);
	    b = findP(b);
	    
	    if(a==b) return;
	    
	    if(siz[a]<siz[b]) swap(a,b);
	    
	    par[b] = a;
	    siz[a] += siz[b];
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int,int>>> edges;
        
        init(V);
        
        for(int i=0; i<V; ++i){
            for(auto it:adj[i]){
              int node = i;
              int adjNode = it[0];
              int wt = it[1];
              
              edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        
        int sum = 0;
        
        for(auto it:edges){
            int wt = it.first;
            int a = it.second.first;
            int b = it.second.second;
            
            if(findP(a) != findP(b)){
                sum += wt;
                merge(a,b);
            }
        }
        return sum;
        
        
    }
};

























//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends