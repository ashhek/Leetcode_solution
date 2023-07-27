class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int>m;
        int ans;

        for(auto it:nums) m[it]++;

        for(auto it:m){
            if(it.second==1) 
            ans = it.first;
        }
        return ans;
    }
};