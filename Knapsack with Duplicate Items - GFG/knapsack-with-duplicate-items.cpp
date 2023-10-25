//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   int f(int i, int W, int wt[], int val[], vector<vector<int>>& dp){
       if(i==0){
           if(W>=wt[0]) return ((W/wt[0]) * val[0]);
           else return 0;
       }
       if(dp[i][W] != -1) return dp[i][W];
       int notPick = f(i-1, W, wt, val, dp);
       int pick = 0;
       if(W>=wt[i]) pick = val[i]+f(i, W-wt[i], wt, val, dp);
       
       return dp[i][W] = max(pick, notPick);
   }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N, vector<int>(W+1, 0));
        //return f(N-1, W, wt, val, dp);
        
        vector<int>prev(W+1, 0), curr(W+1, 0);
        for (int i = wt[0]; i <= W; i++) {
        prev[i] = (i / wt[0]) * val[0];
    }

        
        for(int i=1; i<N; ++i){
            for(int target=0; target<=W; ++target){
                int notPick = prev[target];
                int pick = 0; 
                if(target>=wt[i]) pick = val[i] + curr[target-wt[i]];
                
                curr[target] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends