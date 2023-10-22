class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        for(int i=0; i<nums.size(); ++i){
            int e = abs(nums[i]);
            if(nums[e-1]<0) ans.push_back(abs(nums[i]));
            else
            nums[e-1] *= -1;
        }
        return ans;
    }
};