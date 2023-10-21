//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
   bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
  if(target==0) return true;
  if(i==0) return (target==arr[0]);
   
    if(dp[i][target] != -1) return dp[i][target];
   
    bool notPick = f(i-1, target, arr, dp);
    bool pick = target>=arr[i] ? f(i-1, target-arr[i], arr, dp) : false;
     
    return dp[i][target] = pick | notPick;
}

    public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        vector<vector<int>>dp(n, vector<int>(k+1, false));
        //return f(n-1, k, arr, dp);
        
        for(int i=0; i<n; ++i) dp[i][0] = true;
        
        if(arr[0]<=k) dp[0][arr[0]] = true;
        
        for(int i=1; i<n; ++i){
            for(int tar = 1; tar<=k; ++tar){
                 bool notPick = dp[i-1][tar];
                 bool pick = tar>=arr[i] ? dp[i-1][tar-arr[i]] : false;
                 dp[i][tar] = notPick | pick;
            }
            
        }
        return dp[n-1][k];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends