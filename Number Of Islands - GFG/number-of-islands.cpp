//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int par[10001];
    int siz[10001];
    
    void init(int n){
        for(int i=0; i<n; ++i){
            par[i] = i, siz[i] = 1;
        }
    }
    
    int findP(int a){
        if(par[a]==a) return a;
        return par[a] = findP(par[a]);
    }
    
    void merge(int a, int b){
        a = findP(a);
        b = findP(b);
        
        if(a==b) return;
        
        if(siz[a] < siz[b]) swap(a,b);
        
        par[b] = a;
        siz[a] += siz[b];
    }
    
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        init(n*m);
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        vector<int> ans;
        int offset[] = {0, 1, 0, -1, 0};
        
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            for(int i=0; i<4; ++i){
                int nrow = row + offset[i];
                int ncol = col + offset[i+1];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and vis[nrow][ncol] == 1){
                    int node = row*m + col;
                    int adjNode = nrow*m + ncol;
                    
                    if(findP(node) != findP(adjNode)){
                        cnt--;
                        merge(node, adjNode);
                    }
                }
            }
            ans.push_back(cnt);
            
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends