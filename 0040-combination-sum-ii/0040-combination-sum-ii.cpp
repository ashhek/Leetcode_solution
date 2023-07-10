class Solution {
public:
     set<vector<int>>s;
    void helper(vector<int>&nums, vector<int>&temp, int target, int currsum, int i){
        if(currsum>target) return;
        if(currsum==target){
            s.insert(temp);
        }
        if(i==nums.size()) return;

        currsum += nums[i];
        temp.push_back(nums[i]);
        helper(nums, temp, target, currsum, i+1);

        currsum -= nums[i];
        temp.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        helper(nums, temp, target, currsum, i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(candidates, temp, target, 0, 0);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};