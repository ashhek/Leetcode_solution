class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        int sum = 0;

        for(int i=0; i<n; ++i){
          int j = i+1;
          int k= n-1;
          while(j<k){
            sum = nums[i]+nums[j]+nums[k];
            if(sum==0){
                s.insert({nums[i],nums[j],nums[k]});
                j++; k--;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }
          }
            
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};