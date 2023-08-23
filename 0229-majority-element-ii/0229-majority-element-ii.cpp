class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size()/3;

        unordered_map<int,int> m;

        for(auto it:nums) m[it]++;

        vector<int> ans;

        for(auto it:m){
            if(it.second>n) ans.push_back(it.first);
        }
        return ans;
    }
};