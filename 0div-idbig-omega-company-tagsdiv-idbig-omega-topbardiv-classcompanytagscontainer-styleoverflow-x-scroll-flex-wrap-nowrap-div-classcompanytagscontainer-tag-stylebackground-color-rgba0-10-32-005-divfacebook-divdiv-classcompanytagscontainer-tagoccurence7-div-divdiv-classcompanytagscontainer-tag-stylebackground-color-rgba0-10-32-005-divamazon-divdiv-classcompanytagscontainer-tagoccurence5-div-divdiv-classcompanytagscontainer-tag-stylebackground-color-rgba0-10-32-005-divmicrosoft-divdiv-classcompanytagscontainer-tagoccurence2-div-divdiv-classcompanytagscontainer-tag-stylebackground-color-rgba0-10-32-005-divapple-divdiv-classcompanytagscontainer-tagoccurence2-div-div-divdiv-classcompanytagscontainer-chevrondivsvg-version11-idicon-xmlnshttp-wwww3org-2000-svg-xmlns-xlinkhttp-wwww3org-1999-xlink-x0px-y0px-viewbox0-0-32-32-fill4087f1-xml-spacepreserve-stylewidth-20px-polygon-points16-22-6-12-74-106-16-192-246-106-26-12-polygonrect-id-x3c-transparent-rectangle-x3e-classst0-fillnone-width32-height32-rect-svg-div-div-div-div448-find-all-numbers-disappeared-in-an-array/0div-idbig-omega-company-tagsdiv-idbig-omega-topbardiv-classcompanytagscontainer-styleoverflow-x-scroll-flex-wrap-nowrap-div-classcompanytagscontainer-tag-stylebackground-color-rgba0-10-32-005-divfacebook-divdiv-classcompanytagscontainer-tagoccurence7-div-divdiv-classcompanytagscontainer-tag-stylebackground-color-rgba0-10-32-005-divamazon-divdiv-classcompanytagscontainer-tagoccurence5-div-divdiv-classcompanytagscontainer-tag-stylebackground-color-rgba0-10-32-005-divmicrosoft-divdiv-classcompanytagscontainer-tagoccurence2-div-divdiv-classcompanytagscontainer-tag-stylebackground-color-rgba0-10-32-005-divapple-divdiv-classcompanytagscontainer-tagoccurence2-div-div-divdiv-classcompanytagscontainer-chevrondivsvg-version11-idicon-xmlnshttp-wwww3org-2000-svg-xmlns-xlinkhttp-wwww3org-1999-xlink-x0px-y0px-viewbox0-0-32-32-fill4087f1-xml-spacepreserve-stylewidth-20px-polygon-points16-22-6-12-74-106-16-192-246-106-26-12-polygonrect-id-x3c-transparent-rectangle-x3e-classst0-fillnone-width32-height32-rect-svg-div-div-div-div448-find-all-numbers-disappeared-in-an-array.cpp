class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        vector<int>temp(n, -1);
        for(int i=0; i<nums.size(); ++i){
            int e = nums[i];
            //if(nums[e-1]==-1) continue;
            temp[e-1] = -2;
        }
        for(int i=0; i<nums.size(); ++i){
            if(temp[i] == -1) ans.push_back(i+1);
        }
        return ans;
    }
};