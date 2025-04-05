class Solution {
    vector<vector<int>>subsets;
    void findAllSubsets(int i, vector<int>&nums, vector<int>subset) {
        if(i >= nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        findAllSubsets(i+1, nums, subset);
        subset.pop_back();
        findAllSubsets(i+1, nums, subset);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        findAllSubsets(0, nums, {});

        for(auto& subset : subsets) {
            int xr = 0;
            for(int i : subset) {
                xr ^= i;
            }
            res += xr;
        }
        return res;
    }
};