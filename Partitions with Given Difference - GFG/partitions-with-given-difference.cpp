//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = (int)1e9+7;
  public:
    int countPartitions(int n, int target, vector<int>& nums) {
        // Code here
       // int n = nums.size();
        int sum = 0; for(auto it:nums) sum += it;

        if(sum-target<0) return 0;
        if((sum-target) % 2) return 0;

        int k = (sum-target)/2;

        vector<vector<int>>dp(n, vector<int>(k+1, 0));

        if(nums[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(nums[0]!=0 and nums[0]<=k) dp[0][nums[0]] = 1;

        for(int i=1; i<n; ++i){
            for(int target=0; target<=k; ++target){
                int notPick = dp[i-1][target];
                int pick = 0;
                if(nums[i]<=target) pick = dp[i-1][target-nums[i]];

                dp[i][target] = (pick+notPick)%mod;
            }
        }
        return dp[n-1][k];
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