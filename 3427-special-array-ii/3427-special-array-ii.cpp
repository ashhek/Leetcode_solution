class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>temp;

        int j = 0;
        temp.push_back(j);
        for(int i=1; i<n; ++i){
            if(nums[i]%2 == nums[i-1]%2){
                j++;
            }
            temp.push_back(j);
        }
        vector<bool>ans;
        for(auto it:queries){
            ans.push_back(temp[it[0]]==temp[it[1]]);
        }
        return ans;
    }
};