class Solution {
private:
    int helper(vector<int>& arr){
        int n = arr.size();
        int prev = arr[0];
        int prev2 = 0;

        for(int i=1; i<n; ++i){

            int pick = arr[i];
            if(i>1) pick += prev2;

            int notPick = 0 + prev;

            int curri = max(pick, notPick);

            prev2 = prev;
            prev = curri;
        }
        return prev;
    }    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp1,temp2;
        if(n==1) return nums[0];

        for(int i=0; i<nums.size(); ++i){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(helper(temp1), helper(temp2));
    }
};