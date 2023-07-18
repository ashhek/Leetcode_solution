class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pref[n];
        int suff[n];
        vector<int>ans;
        
        pref[0] = nums[0];
        for(int i=1; i<n; ++i){
            pref[i] = nums[i]*pref[i-1];
        }

        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0; --i){
            suff[i] = nums[i]*suff[i+1];
        }
        
        ans.push_back(suff[1]);

        for(int i=1; i<n-1; ++i)
        ans.push_back(pref[i-1]*suff[i+1]);

        ans.push_back(pref[n-2]);

        return ans;
        

    }
};