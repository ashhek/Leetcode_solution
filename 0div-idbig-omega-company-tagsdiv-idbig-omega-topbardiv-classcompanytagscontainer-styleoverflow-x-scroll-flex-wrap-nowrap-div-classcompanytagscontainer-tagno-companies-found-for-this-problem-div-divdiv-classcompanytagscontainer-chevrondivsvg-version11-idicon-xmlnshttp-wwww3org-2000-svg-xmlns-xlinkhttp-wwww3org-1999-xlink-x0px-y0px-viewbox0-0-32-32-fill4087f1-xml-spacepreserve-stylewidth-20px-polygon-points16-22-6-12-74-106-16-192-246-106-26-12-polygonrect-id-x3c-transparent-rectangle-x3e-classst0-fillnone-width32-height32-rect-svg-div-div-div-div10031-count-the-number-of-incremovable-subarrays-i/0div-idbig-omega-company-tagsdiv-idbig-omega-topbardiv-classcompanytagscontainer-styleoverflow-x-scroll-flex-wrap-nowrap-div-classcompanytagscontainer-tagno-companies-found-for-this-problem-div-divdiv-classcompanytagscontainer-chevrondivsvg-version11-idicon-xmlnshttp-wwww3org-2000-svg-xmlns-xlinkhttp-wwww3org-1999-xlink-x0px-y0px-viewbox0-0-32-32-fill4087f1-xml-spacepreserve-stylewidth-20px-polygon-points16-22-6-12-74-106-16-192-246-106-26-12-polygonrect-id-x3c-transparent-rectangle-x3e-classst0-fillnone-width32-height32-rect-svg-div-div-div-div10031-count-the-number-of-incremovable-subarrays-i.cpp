class Solution {
public:
    bool check(int i,int j, vector<int>&nums){
           stack<int>st;
           int cnt = 0;
        for(int k=0; k<nums.size(); ++k){
            if(k>=i and k<=j) continue;
            else{
                if(cnt==0){
                    st.push(nums[k]);
                    cnt++;
                }
                else if(nums[k]<= st.top()) return false;
                st.push(nums[k]);
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
    
        int ans = 0;
        for(int j=0; j<n; ++j){
        for(int i=j; i<n; ++i){
            if(check(j,i, nums)) ans++;
            else continue;
        }
        }
        return ans;
    }
};