//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& height) {
        // Code here
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        
        int offset[] = {0, 1, 0, -1, 0};
        int n = height.size();
        int m = height[0].size();
        vector<vector<int>>dist(n, vector<int>(m,1e9));
        pq.push({0, {0,0}});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row==n-1 and col == m-1) return diff;
            
            for(int i=0; i<4; ++i){
                int nrow = row + offset[i];
                int ncol = col + offset[i+1];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m){
                    int eff = max(diff, abs(height[nrow][ncol]-height[row][col]));
                    
                    if(eff<dist[nrow][ncol]){
                        dist[nrow][ncol] = eff;
                        pq.push({eff, {nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends