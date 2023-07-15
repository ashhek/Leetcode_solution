class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> s;
        


        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                int start = j+1, end = n-1;
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(start<end){
                    if(nums[start]+nums[end] == newTarget){
                        s.insert({nums[i], nums[j], nums[start], nums[end]});
                        start++; end--;
                    }
                    else if(nums[start]+nums[end]<newTarget){
                        start++;
                    }
                    else end--;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
     

    }
};