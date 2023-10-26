//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    int f(int i, int j, string &s, vector<vector<int>>& dp){
        if(i>=j or j<=i) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i]==s[j]) return dp[i][j] = f(i+1, j-1, s, dp);
        int right = 1 + f(i+1, j, s, dp);
        int left = 1 + f(i, j-1, s, dp);
        
        return dp[i][j] = min(right, left);
    }
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n = S.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(0, n-1, S, dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends