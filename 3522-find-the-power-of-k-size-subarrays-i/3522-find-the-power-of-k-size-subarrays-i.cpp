class Solution {
public:
    bool isOk(vector<int>&temp){
        for(int i=1; i<temp.size(); ++i){
            if(temp[i] != temp[i-1]+1){
                return false;
            }
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        
        for(int i=0; i<nums.size()-k+1; ++i){
            vector<int>temp;
            for(int j=i; j<i+k; ++j){
                temp.push_back(nums[j]);
            }
            if(isOk(temp)){
                ans.push_back(temp.back());
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};