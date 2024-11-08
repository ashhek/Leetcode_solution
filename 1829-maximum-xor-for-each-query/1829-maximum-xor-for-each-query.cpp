class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int limit = pow(2, maximumBit);
        int xr = nums[0];
        vector<int>res;
        int n = nums.size();

        for(int i=1; i<nums.size(); ++i) {
            xr ^= nums[i];
        }
         res.push_back((xr ^ (limit-1)));
        for(int i=n-1; i>0; --i) {
            xr ^= nums[i];
            res.push_back((xr ^ (limit-1)));
        }
        return res;
    }
};