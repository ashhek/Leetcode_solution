class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<int>st;
        unordered_map<int,int>mp;

        for(int i=0; i<n; ++i){
            mp[nums[i]] = i+1;
        }

        for(int i=0; i<n; ++i){
           int f = target - nums[i];

           if(mp.count(f)){
            int j = mp[f]-1;
            if(j!=i) return {i, j};
           }
        }
        return {};
    }
};