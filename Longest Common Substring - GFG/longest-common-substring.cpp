//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        //vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        vector<int>prev(m+1, 0), curr(m+1, 0);
        //for(int i=0; i<n; ++i) prev[0] = 0;
        //for(int i=0; i<m; ++i) dp[0][i] = 0;
        
        int ans = 0;
        
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0;
                ans = max(ans, curr[j]);
            }
            prev = curr;
        }
        return ans;

    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends