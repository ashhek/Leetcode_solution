//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	
         long ans = 0;


        for (int i = 0; i < 32; i++) {

            long zero_cnt = 0;
            long one_cnt = 0;

            for (int j = 0; j < n; j++) {

                if (arr[j] % 2 == 0) {
                    zero_cnt++;
                } else {
                    one_cnt++;
                }


                arr[j] = arr[j] / 2;

            }
            ans += (zero_cnt * one_cnt) * (1 << i);
        }


        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends