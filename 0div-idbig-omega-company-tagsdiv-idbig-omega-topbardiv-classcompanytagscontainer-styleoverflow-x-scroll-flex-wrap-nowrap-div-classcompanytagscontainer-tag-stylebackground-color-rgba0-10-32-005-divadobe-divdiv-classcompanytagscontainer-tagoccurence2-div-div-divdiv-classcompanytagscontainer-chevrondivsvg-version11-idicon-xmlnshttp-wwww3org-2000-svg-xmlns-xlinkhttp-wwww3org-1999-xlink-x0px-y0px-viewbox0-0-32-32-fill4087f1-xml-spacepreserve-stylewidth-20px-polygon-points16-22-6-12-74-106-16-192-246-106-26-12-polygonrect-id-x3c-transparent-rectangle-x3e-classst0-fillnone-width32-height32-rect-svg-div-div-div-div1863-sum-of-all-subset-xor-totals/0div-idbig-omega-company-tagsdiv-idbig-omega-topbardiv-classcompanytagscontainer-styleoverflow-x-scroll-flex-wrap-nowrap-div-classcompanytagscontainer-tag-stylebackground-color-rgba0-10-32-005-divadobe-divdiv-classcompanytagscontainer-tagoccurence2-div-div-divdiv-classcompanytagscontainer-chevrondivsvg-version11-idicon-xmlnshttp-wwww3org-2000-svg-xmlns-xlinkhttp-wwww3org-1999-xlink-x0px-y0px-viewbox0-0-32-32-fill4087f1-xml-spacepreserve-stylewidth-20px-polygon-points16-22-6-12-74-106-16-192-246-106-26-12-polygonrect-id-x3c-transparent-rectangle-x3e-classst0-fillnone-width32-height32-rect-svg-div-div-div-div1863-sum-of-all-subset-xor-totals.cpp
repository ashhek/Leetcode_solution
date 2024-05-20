class Solution {
    void help(int i, vector<int>&nums, vector<vector<int>>&subset, vector<int>temp){
        if(i==nums.size()){
            subset.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        help(i+1, nums, subset, temp);
        temp.pop_back();
        help(i+1, nums, subset, temp);
        
        
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>temp;
        help(0, nums, subset, temp);

        int ans = 0;
        for(auto sub:subset){
            int xr = 0;
            for(auto i:sub){
                xr ^= i;
            }
            ans += xr;
        }
        return ans;
    }

};