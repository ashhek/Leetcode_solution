//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    int mod = (int)(1e9+7);
    private:
    int f(int i, int target, int arr[], vector<vector<int>>& dp){
        
        if(i<0) return target==0;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        int notPick = f(i-1, target, arr, dp);
        int pick = 0;
        if(target>=arr[i]) pick = f(i-1, target-arr[i], arr, dp);
        
        return dp[i][target] = (pick + notPick)%mod;
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return f(n-1, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends