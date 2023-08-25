class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(), nums.end());
    
        int ans;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]==mx) {
                ans = i;
                continue;
            }
            else{
               if(mx < nums[i]*2)
               return -1;
            }
        }
        return ans;
    }
};