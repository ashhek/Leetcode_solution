class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int j=1,i=0,k=1,n=nums.size();
        if(n==0) return res;
        while(j<n){
            if(nums[i]+k!=nums[j]){
                string r=to_string(nums[i]);
                if(j-1>i) r+="->"+to_string(nums[j-1]);
                res.push_back(r);
                k=0,i=j;
            }
            ++k,++j;
        }
        if(k==1) res.push_back(to_string(nums[i]));
        else res.push_back(to_string(nums[i])+"->"+to_string(nums[j-1]));
        return res;
    }
};