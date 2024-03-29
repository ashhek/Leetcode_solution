class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
       
        int e = *max_element(nums.begin(),nums.end());
        long long ans = 0;
        int cnt = 0;
        for(int i=0,j=0; j<nums.size();++j){
           if(nums[j]==e){
            cnt++;
           }
           while(cnt>=k){
            ans += nums.size() - j;
            if(nums[i]==e){
                cnt--;
            }
            i++;
           }
        }
        return ans;
    }
};