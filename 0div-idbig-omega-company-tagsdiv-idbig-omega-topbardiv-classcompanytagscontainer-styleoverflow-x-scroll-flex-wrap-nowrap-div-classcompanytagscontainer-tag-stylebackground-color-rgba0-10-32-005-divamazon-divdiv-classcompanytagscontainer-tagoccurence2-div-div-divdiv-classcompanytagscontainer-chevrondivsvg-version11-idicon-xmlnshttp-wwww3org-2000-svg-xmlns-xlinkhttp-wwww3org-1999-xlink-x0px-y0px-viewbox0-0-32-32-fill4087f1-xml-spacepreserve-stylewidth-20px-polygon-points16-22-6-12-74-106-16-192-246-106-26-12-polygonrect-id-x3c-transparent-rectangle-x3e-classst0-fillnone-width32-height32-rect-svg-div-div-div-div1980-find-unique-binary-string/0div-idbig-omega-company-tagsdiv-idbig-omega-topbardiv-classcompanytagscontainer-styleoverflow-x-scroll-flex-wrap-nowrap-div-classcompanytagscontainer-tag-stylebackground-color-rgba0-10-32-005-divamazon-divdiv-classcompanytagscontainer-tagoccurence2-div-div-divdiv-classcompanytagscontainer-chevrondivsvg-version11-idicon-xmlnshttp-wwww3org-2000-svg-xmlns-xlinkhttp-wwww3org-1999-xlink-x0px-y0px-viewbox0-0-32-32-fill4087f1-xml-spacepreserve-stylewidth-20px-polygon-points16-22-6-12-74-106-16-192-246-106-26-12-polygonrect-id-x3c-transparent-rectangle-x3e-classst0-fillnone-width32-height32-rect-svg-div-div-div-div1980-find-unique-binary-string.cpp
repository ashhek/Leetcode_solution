class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0; i<nums.size(); ++i){
            char curr = nums[i][i]=='1' ? '0':'1';
            ans += curr;
        }
        return ans;
    }
};