class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>map;
        vector<int>ans;
        for(auto num:nums){
            map[num]++;
        }
        for(auto it:map){
            if(it.second != 1)
            ans.push_back(it.first);
        }
        return ans;
    }
};