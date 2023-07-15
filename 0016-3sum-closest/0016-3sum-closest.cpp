class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int check = INT_MAX;
        int ans;


        for(int i=0; i<n; ++i){
            int j=i+1, k = n-1;
            while(j<k){
            int currsum = nums[i]+nums[j]+nums[k];

            if(currsum == target) return currsum;

            else if(check>abs(currsum-target)){
                check = abs(currsum - target);
                ans = currsum;
            }
             
            else if(currsum<target) {
                j++;
            }
            else {
                 k--;
            }
            }
        }
        return ans;
    }
};