//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = (int)(1e9+7);
  private:
  int f(int i, int target, vector<int>& arr,vector<vector<int>>& dp){
      if(i<0) return target==0;
      if(dp[i][target] != -1) return dp[i][target];
      int notPick = f(i-1, target, arr, dp);
      int pick = 0;
      if(arr[i]<=target) pick = f(i-1, target-arr[i], arr, dp);
      
      return dp[i][target] = (pick + notPick)%mod;
  }
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += arr[i];
    }
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr, dp);
        // if(arr[0]==0) dp[0][0] = 2;
        // else dp[0][0] = 1;
        
        // if(arr[0] != 0 and arr[0]<=s2) dp[0][arr[0]] = 1;
        for(int i=0; i<n; ++i) dp[i][0] = 1;
        for(int i=1; i<n; ++i){
            for(int target= 0; target<=s2; ++target){
                
                int notPick = dp[i-1][target];
                int pick = 0;
                if(arr[i]<=target) pick = dp[i-1][target-arr[i]];
                
                dp[i][target] = (pick+notPick)%mod;
            }
        }
        //return dp[n-1][s2];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends