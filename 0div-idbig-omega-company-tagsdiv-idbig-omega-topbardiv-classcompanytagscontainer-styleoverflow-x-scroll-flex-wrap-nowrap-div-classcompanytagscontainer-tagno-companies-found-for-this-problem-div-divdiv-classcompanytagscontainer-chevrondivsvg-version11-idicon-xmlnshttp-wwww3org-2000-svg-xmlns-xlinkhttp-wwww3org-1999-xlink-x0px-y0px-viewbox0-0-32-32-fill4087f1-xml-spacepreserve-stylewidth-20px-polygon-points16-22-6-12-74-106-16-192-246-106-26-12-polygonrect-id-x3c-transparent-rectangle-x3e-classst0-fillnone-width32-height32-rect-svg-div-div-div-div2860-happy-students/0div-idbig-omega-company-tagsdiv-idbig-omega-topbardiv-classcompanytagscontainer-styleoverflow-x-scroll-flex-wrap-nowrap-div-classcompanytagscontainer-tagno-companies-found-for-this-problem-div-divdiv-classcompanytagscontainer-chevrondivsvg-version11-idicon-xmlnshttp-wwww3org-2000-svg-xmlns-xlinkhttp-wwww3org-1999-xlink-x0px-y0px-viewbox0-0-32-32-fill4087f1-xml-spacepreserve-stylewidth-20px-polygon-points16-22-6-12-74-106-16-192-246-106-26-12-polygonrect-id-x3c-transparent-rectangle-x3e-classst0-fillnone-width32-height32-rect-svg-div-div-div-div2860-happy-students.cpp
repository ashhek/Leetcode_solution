class Solution {
public:
    int countWays(vector<int>& nums) {
        int cnt=0;
        int ans=0;
        int zcnt=0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            cnt++;
            if(nums[i]==0){
                zcnt++;
            }
            if(i<nums.size()-1){
              if(cnt>nums[i] && cnt<nums[i+1]){
                  ans++;
              }
            }
            else{
                if(cnt>nums[i]){
                    ans++;
                    if(zcnt==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};